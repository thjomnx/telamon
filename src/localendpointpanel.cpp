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

#include <QtGui>

#include "localendpointpanel.h"
#include "udpreceiverwidget.h"
#include "udpreceiverconfigdialog.h"

LocalEndpointPanel::LocalEndpointPanel(QWidget *parent)
    : QDockWidget(parent)
{
    setupUi(this);

    initUi();
    makeConnections();
}

LocalEndpointPanel::~LocalEndpointPanel()
{
}

void LocalEndpointPanel::initUi()
{
}

void LocalEndpointPanel::makeConnections()
{
    connect(pushButton_Add, SIGNAL(clicked(bool)), this, SLOT(addEndpoint()));
}

void LocalEndpointPanel::addEndpoint()
{
    UdpReceiverConfigDialog dlg(this);

    if (dlg.exec())
    {
        QList<UdpReceiverWidget*> list = scrollAreaWidgetContents->findChildren<UdpReceiverWidget*>();
        UdpReceiverWidget *urw = new UdpReceiverWidget(this);

        qDebug() << "addConnection():" << urw;

        QBoxLayout* layout = static_cast<QBoxLayout*>(scrollAreaWidgetContents->layout());
        layout->insertWidget(list.count(), urw);
    }
}

void LocalEndpointPanel::removeEndpoint()
{
}
