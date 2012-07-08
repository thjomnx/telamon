#ifndef CONNECTIONEDITOR_H
#define CONNECTIONEDITOR_H

#include <QDockWidget>

#include "ui_connectioneditor.h"
#include "udpreceiverwidget.h"

class ConnectionEditor : public QDockWidget, public Ui::ConnectionEditor
{
    Q_OBJECT

public:
    ConnectionEditor(QWidget *parent = 0);
    virtual ~ConnectionEditor();

private slots:
    void addConnection();
    void removeConnection();

private:
    void initUi();
    void makeConnections();
};

#endif // CONNECTIONEDITOR_H
