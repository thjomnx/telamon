#include <QtCore>
#include <QtNetwork>

#include "udpclient.h"

UdpClient::UdpClient()
{
}

UdpClient::~UdpClient()
{
}

void UdpClient::sendData(QString msg)
{
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);

    out << msg;

    qDebug() << "sendData(QString): msg = " << msg;

    socket.writeDatagram(datagram, QHostAddress::LocalHost, 52436);
}
