#include <QtGui>

#include "connectioneditor.h"

ConnectionEditor::ConnectionEditor(QWidget *parent)
    : QDockWidget(parent)
{
    setupUi(this);

    initUi();
    makeConnections();
}

ConnectionEditor::~ConnectionEditor()
{
}

void ConnectionEditor::initUi()
{
}

void ConnectionEditor::makeConnections()
{
    connect(pushButton_Add, SIGNAL(clicked(bool)), this, SLOT(addConnection()));
}

void ConnectionEditor::addConnection()
{
    QList<UdpReceiverWidget*> list = scrollAreaWidgetContents->findChildren<UdpReceiverWidget*>();
    UdpReceiverWidget *urw = new UdpReceiverWidget(this);

    qDebug() << "addConnection():" << urw;

    QVBoxLayout* layout = static_cast<QVBoxLayout*>(scrollAreaWidgetContents->layout());
    layout->insertWidget(list.count(), urw);
}

void ConnectionEditor::removeConnection()
{
}
