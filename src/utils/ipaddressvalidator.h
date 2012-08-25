#ifndef IPADDRESSVALIDATOR_H
#define IPADDRESSVALIDATOR_H

#include <QValidator>

class IpAddressValidator : public QValidator
{

public:
    explicit IpAddressValidator(QObject *parent = 0);
    virtual ~IpAddressValidator();

    virtual void fixup(QString &) const {};
    virtual QValidator::State validate(QString &input, int &pos) const;
};

#endif // IPADDRESSVALIDATOR_H
