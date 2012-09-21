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

#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QObject>
#include <QUdpSocket>

class UdpSender : public QObject
{
    Q_OBJECT

public:
    UdpSender();
    virtual ~UdpSender();

    QHostAddress destAddress() const;
    void setDestAddress(const QHostAddress address);

    quint16 destPort() const;
    void setDestPort(const quint16 port);

    void sendData(const QString &msg);
    void sendData(const QByteArray &datagram);

private:
    QUdpSocket *_socket;

    QHostAddress _destAddress;
    quint16 _destPort;
};

#endif // UDPCLIENT_H
