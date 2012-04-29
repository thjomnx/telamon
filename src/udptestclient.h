#ifndef UDPTESTCLIENT_H
#define UDPTESTCLIENT_H

#include <QObject>
#include <QUdpSocket>

class UdpTestClient : public QObject
{
    Q_OBJECT

public:
    UdpTestClient();
    virtual ~UdpTestClient();

    void sendData();

private:
    QUdpSocket socket;
};

#endif // UDPTESTCLIENT_H
