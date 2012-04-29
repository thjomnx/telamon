#include <QtCore>
#include <QtNetwork>

#include "udptestclient.h"

UdpTestClient::UdpTestClient()
{
}

UdpTestClient::~UdpTestClient()
{
}

void UdpTestClient::sendData()
{
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_8);

    out << "Hello other side!";

    qDebug() << "sendData()";

    socket.writeDatagram(datagram, QHostAddress::LocalHost, 52436);
}
