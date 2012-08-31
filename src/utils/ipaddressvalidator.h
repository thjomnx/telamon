#ifndef IPADDRESSVALIDATOR_H
#define IPADDRESSVALIDATOR_H

#include <QValidator>

class IpAddressValidator : public QValidator
{

public:
    enum ValidatorMode
    {
        Ipv4ValidatorMode,
        Ipv6ValidatorMode
    };

    explicit IpAddressValidator(QObject *parent = 0);
    virtual ~IpAddressValidator();

    void fixup(QString &) const {};
    QValidator::State validate(QString &input, int &pos) const;

    ValidatorMode validatorMode() const { return mode; }
    void setValidatorMode(const ValidatorMode value) { mode = value; };

private:
    QValidator::State validateIpv4(QString &input) const;
    QValidator::State validateIpv6(QString &input) const;

    ValidatorMode mode;
};

#endif // IPADDRESSVALIDATOR_H
