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

#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <QMap>

class LocalEndpoint;

class MainController : public QObject
{
    Q_OBJECT

public:
    MainController();
    virtual ~MainController();

    QMap<int, LocalEndpoint*> localEndpoints() const { return m_localEndpoints; }

    int createLocalEndpoint(const QString &host, const quint16 port);
    void removeLocalEndpoint(const int id);

signals:
    void localEndpointsChanged();

private:
    QMap<int, LocalEndpoint*> m_localEndpoints;
};

extern MainController *controller;

#endif // MAINCONTROLLER_H
