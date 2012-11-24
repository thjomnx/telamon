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

#ifndef LOCALENDPOINTPANEL_H
#define LOCALENDPOINTPANEL_H

#include <QDockWidget>

#include "ui_localendpointpanel.h"

class LocalEndpointPanel : public QDockWidget, public Ui::LocalEndpointPanel
{
    Q_OBJECT

public:
    explicit LocalEndpointPanel(QWidget *parent = 0);
    virtual ~LocalEndpointPanel();

private slots:
    void addEndpoint();
    void removeEndpoint();

private:
    void initUi();
    void makeConnections();
};

#endif // LOCALENDPOINTPANEL_H
