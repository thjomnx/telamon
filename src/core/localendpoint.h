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

#ifndef LOCALENDPOINT_H
#define LOCALENDPOINT_H

#include <QObject>
#include <QHostAddress>

class LocalEndpoint : public QObject
{
    Q_OBJECT

public:
    explicit LocalEndpoint(QHostAddress &address, quint16 port);
    virtual ~LocalEndpoint();

    QHostAddress address() const { return m_address; }
    quint16 port() const { return m_port; }

protected:
    QHostAddress m_address;
    quint16 m_port;
};

#endif // LOCALENDPOINT_H