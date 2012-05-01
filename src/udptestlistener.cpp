#include <QtCore>
#include <QtNetwork>

#include "udptestlistener.h"

UdpTestListener::UdpTestListener()
{
    socket.bind(52436);

    makeConnections();
}

UdpTestListener::~UdpTestListener()
{
}

void UdpTestListener::processPendingDatagrams()
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

void UdpTestListener::makeConnections()
{
    connect(&socket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));
}
