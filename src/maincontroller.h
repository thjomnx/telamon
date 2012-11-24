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

template<class T> class QLinkedList;
class LocalEndpoint;

class MainController : public QObject
{
    Q_OBJECT

public:
    MainController();
    virtual ~MainController();

    QLinkedList<LocalEndpoint*>* localEndpoints() const { return m_locEps; }

private:
    QLinkedList<LocalEndpoint*> *m_locEps;
};

extern MainController *controller;

#endif // MAINCONTROLLER_H
