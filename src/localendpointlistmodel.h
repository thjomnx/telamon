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

#ifndef LOCALENDPOINTLISTMODEL_H
#define LOCALENDPOINTLISTMODEL_H

#include <QAbstractListModel>

class LocalEndpoint;

class LocalEndpointListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    LocalEndpointListModel(QObject *parent = 0);

    void setEndpoints(const QMap<int, LocalEndpoint*> &endpoints);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

private:
    QMap<int, LocalEndpoint*> m_endpoints;
};

#endif // LOCALENDPOINTLISTMODEL_H
