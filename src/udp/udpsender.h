#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QObject>
#include <QUdpSocket>

class UdpSender : public QObject
{
    Q_OBJECT

public:
    UdpSender();
    virtual ~UdpSender();

    QHostAddress destAddress() const;
    void setDestAddress(const QHostAddress address);

    quint16 destPort() const;
    void setDestPort(const quint16 port);

    void sendData(const QString &msg);
    void sendData(const QByteArray &datagram);

private:
    QUdpSocket *_socket;

    QHostAddress _destAddress;
    quint16 _destPort;
};

#endif // UDPCLIENT_H
