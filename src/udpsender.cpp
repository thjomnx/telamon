#include <QtCore>
#include <QtNetwork>

#include "udpsender.h"

UdpSender::UdpSender()
{
    _destPort = 0;
    _socket = new QUdpSocket(this);
}

UdpSender::~UdpSender()
{
}

QHostAddress UdpSender::destAddress() const
{
    return _destAddress;
}

void UdpSender::setDestAddress(const QHostAddress address)
{
    _destAddress = address;
}

quint16 UdpSender::destPort() const
{
    return _destPort;
}

void UdpSender::setDestPort(const quint16 port)
{
    _destPort = port;
}

void UdpSender::sendData(const QString &msg)
{
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);
    out << msg;

    sendData(datagram);
}

void UdpSender::sendData(const QByteArray &datagram)
{
    qDebug() << "sendData(QString): datagram = " << datagram;

    _socket->writeDatagram(datagram, _destAddress, _destPort);
}
