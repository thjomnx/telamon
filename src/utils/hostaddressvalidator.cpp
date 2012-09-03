#include <QStringList>
#include <QDebug>

#include "hostaddressvalidator.h"

HostAddressValidator::HostAddressValidator(QObject *parent)
    : QValidator(parent)
{
    mode = Ipv6ValidatorMode;
}

HostAddressValidator::~HostAddressValidator()
{
}

QValidator::State HostAddressValidator::validate(QString &input, int &pos) const
{
    if (input.isEmpty())
    {
        qDebug() << "--> Result: Intermediate";
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
    QStringList slist = input.split(".");
    int s = slist.size();

    if (s > 4)
    {
        qDebug() << "--> IPv4 result: Invalid";
        return Invalid;
    }

    bool emptyBlock = false;

    for (int i = 0; i < s; i++)
    {
        bool ok;

        if (slist[i].isEmpty())
        {
            emptyBlock = true;
            continue;
        }

        int val = slist[i].toInt(&ok);

        if (!ok || val < 0 || val > 255)
        {
            qDebug() << "--> IPv4 result: Invalid";
            return Invalid;
        }
    }

    if (s < 4 || emptyBlock)
    {
        qDebug() << "--> IPv4 result: Intermediate";
        return Intermediate;
    }

    qDebug() << "--> IPv4 result: Acceptable";
    return Acceptable;
}

QValidator::State HostAddressValidator::validateIpv6(QString &input) const
{
    qDebug() << "Analyzing input: " << input;

    QStringList list = input.split(':');
    int length = list.size();

    // Check total number of blocks
    if (length > 8)
    {
        qDebug() << "--> IPv6 result: Invalid";
        return Invalid;
    }

    int start = 0;
    int end = length;
    int numBlocks = 0;
    int emptyBlock = -1;

    bool ipv4Trail = false;
    State ipv4Result = Acceptable;

    if (length > 2)
    {
        // Check for compressed head
        if (list[0].isEmpty() && list[1].isEmpty())
        {
            qDebug() << "Head is compressed";
            start += 2;
        }
        else
        {
            // Check for compressed tail
            if (list[length - 2].isEmpty() && list[length - 1].isEmpty())
            {
                qDebug() << "Tail is compressed";
                end -= 2;
            }
        }
    }

    for (int i = start; i < end; i++)
    {
        qDebug() << "Checking " << list[i] << "[" << list[i].length() << "]";

        bool ok;

        // Check for empty blocks
        if (list[i].isEmpty())
        {
            if (length > 3 && (start > 0 || end < length))
            {
                qDebug() << "Empty block found after compressed head/tail at index" << i;
                qDebug() << "--> IPv6 result: Intermediate";
                return Intermediate;
            }
            else
            {
                if (emptyBlock > -1)
                {
                    qDebug() << "Second empty block found at index" << i;
                    qDebug() << "--> IPv6 result: Intermediate";
                    return Intermediate;
                }

                emptyBlock = i;

                continue;
            }
        }

        // Check for possible trailing IPv4 block
        ipv4Trail = i == end - 1 && list[i].contains('.');

        if (ipv4Trail)
        {
            // Validate IPv4 block characters
            ipv4Result = validateIpv4(list[i]);

            if (ipv4Result == Invalid)
            {
                qDebug() << "--> IPv6 result: Invalid";
                return Invalid;
            }

            numBlocks++;
        }
        else
        {
            // Validate IPv6 block length
            if (list[i].length() > 4)
            {
                qDebug() << "--> IPv6 result: Invalid";
                return Invalid;
            }

            // Validate IPv6 block characters
            int value = list[i].toInt(&ok, 16);

            if (!ok || value < 0 || value > 65535)
            {
                qDebug() << "--> IPv6 result: Invalid";
                return Invalid;
            }

            numBlocks++;
        }
    }

    // Check for minimum blocks and IPv4 result
    if (length < 3 || ipv4Result == Intermediate)
    {
        qDebug() << "--> IPv6 result: Intermediate";
        return Intermediate;
    }

    if (start == 0 && end == length)
    {
        qDebug() << "Index of single empty block:" << emptyBlock;
        qDebug() << "Total number of blocks:" << numBlocks;

        if (emptyBlock == 0 || emptyBlock == length - 1)
        {
            qDebug() << "--> IPv6 result: Intermediate";
            return Intermediate;
        }
        else
        {
            if (emptyBlock == -1)
            {
                if (numBlocks < 8)
                {
                    qDebug() << "--> IPv6 result: Intermediate";
                    return Intermediate;
                }
            }
        }
    }

    qDebug() << "--> IPv6 result: Acceptable";
    return Acceptable;
}
