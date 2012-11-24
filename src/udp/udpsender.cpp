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

#include "udpsender.h"

UdpSender::UdpSender()
{
    m_destPort = 0;
    m_socket = new QUdpSocket(this);
}

UdpSender::~UdpSender()
{
}

QHostAddress UdpSender::destAddress() const
{
    return m_destAddr;
}

void UdpSender::setDestAddress(const QHostAddress address)
{
    m_destAddr = address;
}

quint16 UdpSender::destPort() const
{
    return m_destPort;
}

void UdpSender::setDestPort(const quint16 port)
{
    m_destPort = port;
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

    m_socket->writeDatagram(datagram, m_destAddr, m_destPort);
}
