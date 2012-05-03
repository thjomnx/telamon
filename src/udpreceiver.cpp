#include <QtCore>
#include <QtNetwork>

#include "udpreceiver.h"

UdpReceiver::UdpReceiver()
{
    socket.bind(52436);

    makeConnections();
}

UdpReceiver::~UdpReceiver()
{
}

void UdpReceiver::processPendingDatagrams()
{
    QByteArray datagram;

    do
    {
        datagram.resize(socket.pendingDatagramSize());
        socket.readDatagram(datagram.data(), datagram.size());
    }
    while (socket.hasPendingDatagrams());

    QString msg;

    QDataStream in(&datagram, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_4_8);

    in >> msg;

    qDebug() << "processPendingDatagrams(): msg = " << msg;
}

void UdpReceiver::makeConnections()
{
    connect(&socket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));
}
