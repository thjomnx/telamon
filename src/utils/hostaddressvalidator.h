#ifndef HOSTADDRESSVALIDATOR_H
#define HOSTADDRESSVALIDATOR_H

#include <QValidator>

class HostAddressValidator : public QValidator
{

public:
    enum ValidatorMode
    {
        Ipv4ValidatorMode,
        Ipv6ValidatorMode
    };

    explicit HostAddressValidator(QObject *parent = 0);
    virtual ~HostAddressValidator();

    void fixup(QString &) const {};
    QValidator::State validate(QString &input, int &pos) const;

    ValidatorMode validatorMode() const { return mode; }
    void setValidatorMode(const ValidatorMode value) { mode = value; };

private:
    QValidator::State validateIpv4(QString &input) const;
    QValidator::State validateIpv6(QString &input) const;

    ValidatorMode mode;
};

#endif // HOSTADDRESSVALIDATOR_H
