/**
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

#ifndef UDPRECEIVERCONFIGDIALOG_H
#define UDPRECEIVERCONFIGDIALOG_H

#include <QDialog>

#include "ui_udpreceiverconfigdialog.h"

class HostAddressValidator;

class UdpReceiverConfigDialog : public QDialog, public Ui::UdpReceiverConfigDialog
{
    Q_OBJECT

public:
    UdpReceiverConfigDialog(QWidget *parent = 0, Qt::WindowFlags f = 0);
    virtual ~UdpReceiverConfigDialog();

private slots:
    void on_radioButton_Ipv4_clicked();
    void on_radioButton_Ipv6_clicked();
    void on_comboBox_Address_editTextChanged();
    void on_spinBox_Port_valueChanged();

private:
    void initUi();
    void makeConnections();

    void updateUi();

    HostAddressValidator *validator;
};

#endif // UDPRECEIVERCONFIGDIALOG_H
