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
