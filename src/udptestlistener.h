#ifndef UDPTESTLISTENER_H
#define UDPTESTLISTENER_H

#include <QObject>
#include <QUdpSocket>

class UdpTestListener : public QObject
{
    Q_OBJECT

public:
    UdpTestListener();
    virtual ~UdpTestListener();

private slots:
    void processPendingDatagrams();

private:
    void makeConnections();

    QUdpSocket socket;
};

#endif // UDPTESTLISTENER_H
