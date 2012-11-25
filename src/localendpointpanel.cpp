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
#include "maincontroller.h"
#include "udpreceiver.h"
#include "udpreceiverwidget.h"
#include "udpreceiverconfigdialog.h"

LocalEndpointPanel::LocalEndpointPanel(QWidget *parent)
    : QDockWidget(parent)
{
    setupUi(this);

    makeConnections();
    updateUi();
}

LocalEndpointPanel::~LocalEndpointPanel()
{
}

void LocalEndpointPanel::updateUi()
{
    // Clear child widgets
    QList<UdpReceiverWidget*> children = scrollAreaWidgetContents->findChildren<UdpReceiverWidget*>();

    foreach(UdpReceiverWidget *widget, children)
    {
        delete widget;
    }

    // Walk through endpoints and add a widget for each one
    QBoxLayout *layout = static_cast<QBoxLayout*>(scrollAreaWidgetContents->layout());
    QList<LocalEndpoint*> endpoints = controller->localEndpoints();

    foreach(LocalEndpoint *endpoint, endpoints)
    {
        UdpReceiverWidget *urw = new UdpReceiverWidget(this, endpoint);
        layout->insertWidget(0, urw);
    }
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
        QHostAddress address = QHostAddress(dlg.hostAddress());
        quint16 port = dlg.portNumber();

        UdpReceiver *receiver = new UdpReceiver(address, port);
        controller->addLocalEndpoint(receiver);

        updateUi();
    }
}

void LocalEndpointPanel::removeEndpoint()
{
}
