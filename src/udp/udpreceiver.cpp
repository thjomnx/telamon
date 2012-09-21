/**
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
