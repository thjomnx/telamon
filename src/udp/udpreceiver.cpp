/*
 * This file is part of 'telamon'.
 *
 *    'telamon' is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    'telamon' is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with 'telamon'. If not, see <http://www.gnu.org/licenses/>.
 */

#include <QtCore>
#include <QtNetwork>

#include "udpreceiver.h"

UdpReceiver::UdpReceiver(QHostAddress &address, quint16 port)
    : LocalEndpoint(address, port)
{
    m_socket = new QUdpSocket();
    m_socket->bind(address, port);

    makeConnections();
}

UdpReceiver::~UdpReceiver()
{
    delete m_socket;
}

void UdpReceiver::makeConnections()
{
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));
}

void UdpReceiver::processPendingDatagrams()
{
    QByteArray datagram;

    do
    {
        datagram.resize(m_socket->pendingDatagramSize());
        m_socket->readDatagram(datagram.data(), datagram.size());

        emit dataReceived(datagram);
    }
    while (m_socket->hasPendingDatagrams());

#ifdef DEBUG
    QString msg;

    QDataStream in(&datagram, QIODevice::ReadOnly);
    in.setVersion(QDataStream::Qt_4_8);

    in >> msg;

    qDebug() << "processPendingDatagrams(): msg = " << msg;
#endif
}
