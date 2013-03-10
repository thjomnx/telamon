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

#include "localendpointlistmodel.h"
#include <localendpoint.h>

LocalEndpointListModel::LocalEndpointListModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

void LocalEndpointListModel::setEndpoints(const QMap<int, LocalEndpoint*> &endpoints)
{
    beginResetModel();
    m_endpoints = endpoints;
    endResetModel();
}

int LocalEndpointListModel::rowCount(const QModelIndex &parent) const
{
    return m_endpoints.count();
}

QVariant LocalEndpointListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    if (role == Qt::DisplayRole)
    {
        LocalEndpoint *endpoint = m_endpoints.value(index.row());
        return QString("L %1:%2").arg(endpoint->address().toString()).arg(endpoint->port());
    }

    return QVariant();
}

QVariant LocalEndpointListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QAbstractItemModel::headerData(section, orientation, role);
}
