#include <QtCore>
#include <QtNetwork>

#include "udptestlistener.h"

UdpTestListener::UdpTestListener()
{
    makeConnections();

    socket.bind(52436);
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

        qDebug() << "processPendingDatagrams()";
    }
    while (socket.hasPendingDatagrams());

    QString message;

    QDataStream in(&datagram, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_4_8);

    in >> message;

    qDebug() << message;
}

void UdpTestListener::makeConnections()
{
    connect(&socket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));
}
