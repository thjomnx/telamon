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

#ifndef UDPRECEIVERWIDGET_H
#define UDPRECEIVERWIDGET_H

#include <QWidget>

#include "ui_udpreceiverwidget.h"

class LocalEndpoint;

class UdpReceiverWidget : public QWidget, public Ui::UdpReceiverWidget
{
    Q_OBJECT

public:
    explicit UdpReceiverWidget(QWidget *parent = 0, LocalEndpoint *endpoint = 0);
    virtual ~UdpReceiverWidget();

    LocalEndpoint* endpoint() const { return m_endpoint; }

private slots:
    void subjectUpdated();

private:
    void updateUi();

    LocalEndpoint *m_endpoint;
};

#endif // UDPRECEIVERWIDGET_H
