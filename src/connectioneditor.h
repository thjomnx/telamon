#ifndef CONNECTIONEDITOR_H
#define CONNECTIONEDITOR_H

#include <QDockWidget>

#include "ui_connectioneditor.h"

class ConnectionEditor : public QDockWidget, public Ui::ConnectionEditor
{
    Q_OBJECT

public:
    ConnectionEditor(QWidget *parent = 0);
    virtual ~ConnectionEditor();
};

#endif // CONNECTIONEDITOR_H
