#include <QtGui>

#include "connectioneditor.h"

ConnectionEditor::ConnectionEditor(QWidget *parent)
    : QDockWidget(parent)
{
    setupUi(this);
}

ConnectionEditor::~ConnectionEditor()
{
}

void ConnectionEditor::initUi()
{
    QList<UdpReceiverWidget*> list = scrollAreaWidgetContents->findChildren<UdpReceiverWidget*>();

    if (list.count() < 1)
    {
        pushButton_Remove->setEnabled(false);
    }
}

void ConnectionEditor::makeConnections()
{
    connect(pushButton_Add, SIGNAL(clicked(bool)), this, SLOT(addConnection()));
    connect(pushButton_Remove, SIGNAL(clicked(bool)), this, SLOT(removeConnection()));
}

void ConnectionEditor::addConnection()
{
}

void ConnectionEditor::removeConnection()
{
}
