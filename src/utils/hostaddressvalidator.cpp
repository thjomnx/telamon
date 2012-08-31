#include <QStringList>
#include <QDebug>

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



QValidator::State HostAddressValidator::validateIpv4(QString& input) const
{
    QStringList slist = input.split(".");
    int s = slist.size();

    if (s > 4)
    {
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
            return Invalid;
        }
    }

    if (s < 4 || emptyBlock)
    {
        return Intermediate;
    }

    return Acceptable;
}

QValidator::State HostAddressValidator::validateIpv6(QString& input) const
{
    QStringList list = input.split(':');
    int length = list.size();

    if (length > 8)
    {
        return Invalid;
    }

    bool emptyBlock = false;
    bool lastEmpty = false;

    for (int i = 0; i < length; i++)
    {
        bool ok;

        if (list[i].isEmpty())
        {
            if (i > 1 && i < length - 1 && lastEmpty)
            {
                qDebug() << "i = " << i << " / lastEmpty = " << lastEmpty;
                emptyBlock = true;
            }

            lastEmpty = true;

            continue;
        }
        else
        {
            lastEmpty = false;
        }

        int value = list[i].toInt(&ok, 16);

        if (!ok || value < 0 || value > 65535)
        {
            return Invalid;
        }
    }

    if (length < 3 || emptyBlock)
    {
        return Intermediate;
    }

    return Acceptable;
}
