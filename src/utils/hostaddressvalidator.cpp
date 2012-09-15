#include <QStringList>

#include "hostaddressvalidator.h"

HostAddressValidator::HostAddressValidator(QObject *parent)
    : QValidator(parent)
{
    mode = Ipv4ValidatorMode;
}

HostAddressValidator::~HostAddressValidator()
{
}

QValidator::State HostAddressValidator::validate(QString &input, int &pos) const
{
    if (input.isEmpty())
    {
        return Intermediate;
    }

    if (mode == Ipv4ValidatorMode)
    {
        return validateIpv4(input);
    }
    else
    {
        return validateIpv6(input);
    }
}

QValidator::State HostAddressValidator::validateIpv4(QString &input) const
{
    QStringList list = input.split('.');
    int length = list.size();

    // Check total number of blocks
    if (length > 4)
    {
        return Invalid;
    }

    bool emptyBlock = false;

    for (int i = 0; i < length; i++)
    {
        // Check for empty blocks
        if (list[i].isEmpty())
        {
            emptyBlock = true;
            continue;
        }

        // Validate IPv4 block value
        bool ok;
        int value = list[i].toInt(&ok);

        if (!ok || value < 0 || value > 255)
        {
            return Invalid;
        }
    }

    // Check for minimum block count
    if (length < 4 || emptyBlock)
    {
        return Intermediate;
    }

    return Acceptable;
}

QValidator::State HostAddressValidator::validateIpv6(QString &input) const
{
    QStringList list = input.split(':');
    int length = list.size();

    // Check total number of blocks
    if (length > 8)
    {
        return Invalid;
    }

    uint startIdx = 0;
    uint endIdx = length;
    int emptyBlockIdx = -1;
    uint numNonEmptyBlocks = 0;
    State ipv4Result = Acceptable;

    if (length > 2)
    {
        // Check for compressed head
        if (list[0].isEmpty() && list[1].isEmpty())
        {
            startIdx += 2;
        }
        else
        {
            // Check for compressed tail
            if (list[length - 2].isEmpty() && list[length - 1].isEmpty())
            {
                endIdx -= 2;
            }
        }
    }

    for (int i = startIdx; i < endIdx; i++)
    {
        // Check for empty blocks
        if (list[i].isEmpty())
        {
            if (length > 3 && (startIdx > 0 || endIdx < length))
            {
                return Intermediate;
            }
            else
            {
                if (emptyBlockIdx > -1)
                {
                    return Intermediate;
                }

                emptyBlockIdx = i;

                continue;
            }
        }

        // Check for possible trailing IPv4 block
        if (i == endIdx - 1 && list[i].contains('.'))
        {
            ipv4Result = validateIpv4(list[i]);

            if (ipv4Result == Invalid)
            {
                return Invalid;
            }

            numNonEmptyBlocks++;
        }
        else
        {
            // Validate IPv6 block length
            if (list[i].length() > 4)
            {
                return Invalid;
            }

            // Validate IPv6 block value
            bool ok;
            int value = list[i].toInt(&ok, 16);

            if (!ok || value < 0 || value > 65535)
            {
                return Invalid;
            }

            numNonEmptyBlocks++;
        }
    }

    // Check for minimum block count and IPv4 result
    if (length < 3 || ipv4Result == Intermediate)
    {
        return Intermediate;
    }

    if (startIdx == 0 && endIdx == length)
    {
        // Check for leading and trailing single empty blocks
        if (emptyBlockIdx == 0 || emptyBlockIdx == length - 1)
        {
            return Intermediate;
        }
        else
        {
            // Check for total number of non-empty blocks
            if (emptyBlockIdx == -1)
            {
                if (numNonEmptyBlocks < 8)
                {
                    return Intermediate;
                }
            }
        }
    }

    return Acceptable;
}
