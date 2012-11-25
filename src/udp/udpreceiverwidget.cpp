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
#include <QHostAddress>

#include "udpreceiverwidget.h"
#include <localendpoint.h>

UdpReceiverWidget::UdpReceiverWidget(QWidget *parent, LocalEndpoint *endpoint)
    : QWidget(parent)
{
    setupUi(this);

    m_endpoint = endpoint;

    updateUi();
}

UdpReceiverWidget::~UdpReceiverWidget()
{
}

void UdpReceiverWidget::subjectUpdated()
{
    updateUi();
}

void UdpReceiverWidget::updateUi()
{
    QString text = m_endpoint->address().toString();
    text.append(':');
    text.append(QString::number(m_endpoint->port()));

    label->setText(text);
}
