#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QObject>
#include <QUdpSocket>

class UdpClient : public QObject
{
    Q_OBJECT

public:
    UdpClient();
    virtual ~UdpClient();

    void sendData(QString msg);

private:
    QUdpSocket socket;
};

#endif // UDPCLIENT_H
