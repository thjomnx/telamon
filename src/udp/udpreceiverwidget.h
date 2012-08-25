#ifndef UDPRECEIVERWIDGET_H
#define UDPRECEIVERWIDGET_H

#include <QWidget>

#include "ui_udpreceiverwidget.h"

class UdpReceiverWidget : public QWidget, public Ui::UdpReceiverWidget
{
    Q_OBJECT

public:
    explicit UdpReceiverWidget(QWidget *parent = 0);
    virtual ~UdpReceiverWidget();
};

#endif // UDPRECEIVERWIDGET_H
