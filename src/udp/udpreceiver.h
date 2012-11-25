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

#ifndef UDPRECEIVER_H
#define UDPRECEIVER_H

#include <QHostAddress>

#include "localendpoint.h"

class QUdpSocket;

class UdpReceiver : public LocalEndpoint
{
    Q_OBJECT

public:
    explicit UdpReceiver(QHostAddress &address, quint16 port);
    virtual ~UdpReceiver();

    QUdpSocket* socket() const { return m_socket; }

signals:
    void dataReceived(QByteArray &datagram);

private:
    void makeConnections();

    QUdpSocket *m_socket;

private slots:
    void readDatagrams();
};

#endif // UDPRECEIVER_H
