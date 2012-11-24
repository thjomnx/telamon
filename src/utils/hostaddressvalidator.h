/*
 * This file is part of 'telamon'.
 *
 *    'telamon' is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    'telamon' is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with 'telamon'. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef HOSTADDRESSVALIDATOR_H
#define HOSTADDRESSVALIDATOR_H

#include <QValidator>

class HostAddressValidator : public QValidator
{
    Q_OBJECT

public:
    enum ValidatorMode
    {
        Ipv4ValidatorMode,
        Ipv6ValidatorMode,
        MixedValidatorMode
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
