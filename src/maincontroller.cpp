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

#include "maincontroller.h"
#include "udpreceiver.h"

MainController::MainController()
    : QObject()
{
}

MainController::~MainController()
{
}

int MainController::createLocalEndpoint(const QString &host, const quint16 port)
{
    QHostAddress addr = QHostAddress(host);
    UdpReceiver *recv = new UdpReceiver(addr, port);
    int id = m_localEndpoints.count();

    m_localEndpoints.insert(id, recv);

    emit localEndpointsChanged();

    return id;
}

void MainController::removeLocalEndpoint(const int id)
{
    m_localEndpoints.remove(id);
}
