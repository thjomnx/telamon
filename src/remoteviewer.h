#ifndef REMOTEVIEWER_H
#define REMOTEVIEWER_H

#include <QDockWidget>

#include "ui_remoteviewer.h"

class RemoteViewer : public QDockWidget, public Ui::RemoteViewer
{
    Q_OBJECT

public:
    explicit RemoteViewer(QWidget *parent = 0);
    virtual ~RemoteViewer();
};

#endif // REMOTEVIEWER_H
