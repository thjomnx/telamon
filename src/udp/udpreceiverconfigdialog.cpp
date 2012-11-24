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

#include <QtGui>

#include "udpreceiverconfigdialog.h"
#include "hostaddressvalidator.h"

UdpReceiverConfigDialog::UdpReceiverConfigDialog(QWidget *parent, Qt::WindowFlags f)
    : QDialog(parent, f)
{
    setupUi(this);

    initUi();
    makeConnections();
}

UdpReceiverConfigDialog::~UdpReceiverConfigDialog()
{
    delete validator;
}

QString UdpReceiverConfigDialog::hostAddress() const
{
    return comboBox_Address->currentText().trimmed();
}

int UdpReceiverConfigDialog::portNumber() const
{
    return spinBox_Port->value();
}

void UdpReceiverConfigDialog::initUi()
{
    buttonBox_OkCancel->button(QDialogButtonBox::Ok)->setEnabled(false);

    validator = new HostAddressValidator(this);
    comboBox_Address->setValidator(validator);
}

void UdpReceiverConfigDialog::makeConnections()
{
    connect(buttonBox_OkCancel, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox_OkCancel, SIGNAL(rejected()), this, SLOT(reject()));
}

void UdpReceiverConfigDialog::updateUi()
{
    bool valid = comboBox_Address->lineEdit()->hasAcceptableInput();
    valid &= spinBox_Port->value() > 0 ? true : false;

    buttonBox_OkCancel->button(QDialogButtonBox::Ok)->setEnabled(valid);
}

void UdpReceiverConfigDialog::on_radioButton_Ipv4_clicked()
{
    validator->setValidatorMode(HostAddressValidator::Ipv4ValidatorMode);
    comboBox_Address->lineEdit()->clear();
}

void UdpReceiverConfigDialog::on_radioButton_Ipv6_clicked()
{
    validator->setValidatorMode(HostAddressValidator::Ipv6ValidatorMode);
    comboBox_Address->lineEdit()->clear();
}

void UdpReceiverConfigDialog::on_comboBox_Address_editTextChanged()
{
    updateUi();
}

void UdpReceiverConfigDialog::on_spinBox_Port_valueChanged()
{
    updateUi();
}
