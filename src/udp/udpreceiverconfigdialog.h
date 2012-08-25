#ifndef UDPRECEIVERCONFIGDIALOG_H
#define UDPRECEIVERCONFIGDIALOG_H

#include <QDialog>

#include "ui_udpreceiverconfigdialog.h"

class UdpReceiverConfigDialog : public QDialog, public Ui::UdpReceiverConfigDialog
{
    Q_OBJECT

public:
    UdpReceiverConfigDialog(QWidget *parent = 0, Qt::WindowFlags f = 0);
    virtual ~UdpReceiverConfigDialog();

private:
    void initUi();
    void makeConnections();

private slots:
    void on_comboBox_Address_editTextChanged();
};

#endif // UDPRECEIVERCONFIGDIALOG_H
