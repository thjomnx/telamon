#include <QtGui>

#include "mainwindow.h"

MainWindow::MainWindow()
    : QMainWindow()
{
    setupUi(this);

    createActions();
    createMenus();

    makeConnections();
}

void MainWindow::about()
{
    QString infoText = tr("There isn't so much yet ...");
    QMessageBox::about(this, tr("About Telamon"), infoText);
}

void MainWindow::createActions()
{
    quitAction = new QAction(tr("&Quit"), this);
    quitAction->setShortcut(QKeySequence::Quit);
    quitAction->setStatusTip(tr("Terminate all sessions and quit the application"));

    aboutAction = new QAction(tr("&About"), this);
    aboutAction->setStatusTip(tr("Show some infos about this application"));
}

void MainWindow::createMenus()
{
    menu_File->addAction(quitAction);
    menu_Help->addAction(aboutAction);
}

void MainWindow::makeConnections()
{
    connect(quitAction, SIGNAL(triggered(bool)), this, SLOT(close()));
    connect(aboutAction, SIGNAL(triggered(bool)), this, SLOT(about()));
}
