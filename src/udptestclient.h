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

    void sendData(QString msg);

private:
    QUdpSocket socket;
};

#endif // UDPTESTCLIENT_H
