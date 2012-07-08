#include <QtGui>

#include "remoteviewer.h"

RemoteViewer::RemoteViewer(QWidget *parent)
    : QDockWidget(parent)
{
    setupUi(this);
}

RemoteViewer::~RemoteViewer()
{
}
