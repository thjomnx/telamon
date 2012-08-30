#include <QtGui>

#include "connectioneditor.h"
#include "udpreceiverwidget.h"
#include "udpreceiverconfigdialog.h"

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
    UdpReceiverConfigDialog dlg(this);

    if (dlg.exec())
    {
        QList<UdpReceiverWidget*> list = scrollAreaWidgetContents->findChildren<UdpReceiverWidget*>();
        UdpReceiverWidget *urw = new UdpReceiverWidget(this);

        qDebug() << "addConnection():" << urw;

        QBoxLayout* layout = static_cast<QBoxLayout*>(scrollAreaWidgetContents->layout());
        layout->insertWidget(list.count(), urw);
    }
}

void ConnectionEditor::removeConnection()
{
}
