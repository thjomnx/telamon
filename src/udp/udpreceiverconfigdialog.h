#ifndef UDPRECEIVERCONFIGDIALOG_H
#define UDPRECEIVERCONFIGDIALOG_H

#include <QDialog>

#include "ui_udpreceiverconfigdialog.h"

class UdpReceiverConfigDialog : public QDialog
{

    Q_OBJECT

public:
    UdpReceiverConfigDialog(QWidget* parent = 0, Qt::WindowFlags f = 0);
    virtual ~UdpReceiverConfigDialog();
};

#endif // UDPRECEIVERCONFIGDIALOG_H
