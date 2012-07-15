#ifndef UDPLISTENER_H
#define UDPLISTENER_H

#include <QObject>
#include <QUdpSocket>

class UdpReceiver : public QObject
{
    Q_OBJECT

public:
    UdpReceiver();
    virtual ~UdpReceiver();

private slots:
    void processPendingDatagrams();

private:
    void makeConnections();

    QUdpSocket socket;
};

#endif // UDPLISTENER_H
