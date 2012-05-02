#ifndef UDPLISTENER_H
#define UDPLISTENER_H

#include <QObject>
#include <QUdpSocket>

class UdpListener : public QObject
{
    Q_OBJECT

public:
    UdpListener();
    virtual ~UdpListener();

private slots:
    void processPendingDatagrams();

private:
    void makeConnections();

    QUdpSocket socket;
};

#endif // UDPLISTENER_H
