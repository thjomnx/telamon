#include <QStringList>

#include "ipaddressvalidator.h"

IpAddressValidator::IpAddressValidator(QObject *parent)
    : QValidator(parent)
{
}

IpAddressValidator::~IpAddressValidator()
{
}

QValidator::State IpAddressValidator::validate(QString &input, int &pos) const
{
    if (input.isEmpty())
    {
        return Acceptable;
    }

    QStringList slist = input.split(".");
    int s = slist.size();

    if (s > 4)
    {
        return Invalid;
    }

    bool emptyGroup = false;

    for (int i = 0; i < s; i++)
    {
        bool ok;

        if (slist[i].isEmpty())
        {
            emptyGroup = true;
            continue;
        }

        int val = slist[i].toInt(&ok);

        if (!ok || val < 0 || val > 255)
        {
            return Invalid;
        }
    }

    if (s < 4 || emptyGroup)
    {
        return Intermediate;
    }

    return Acceptable;
}
