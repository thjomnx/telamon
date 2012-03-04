#include <iostream>

#include <QtGui>

#include "mainwindow.h"

MainWindow::MainWindow()
    : QMainWindow()
{
    setupUi(this);

    createChilds();
    createActions();
    createMenus();

    makeConnections();
}

MainWindow::~MainWindow()
{
    delete macroEditor;
}

void MainWindow::showAboutBox()
{
    QString infoText = tr("There isn't so much yet ...");
    QMessageBox::about(this, tr("About Telamon"), infoText);
}

void MainWindow::createChilds()
{
    macroEditor = new MacroEditor();
}

void MainWindow::createActions()
{
    action_Quit = new QAction(tr("&Quit"), this);
    action_Quit->setShortcut(QKeySequence::Quit);
    action_Quit->setStatusTip(tr("Terminate all sessions and quit the application"));

    action_MacroEditor = new QAction(tr("&Macro Editor"), this);
    action_MacroEditor->setCheckable(true);
    action_MacroEditor->setShortcut(tr("Ctrl+M"));
    action_MacroEditor->setStatusTip(tr("Show or hide the macro editor"));

    action_AboutBox = new QAction(tr("&About"), this);
    action_AboutBox->setStatusTip(tr("Show some infos about this application"));
}

void MainWindow::createMenus()
{
    menu_File->addAction(action_Quit);
    menu_View->addAction(action_MacroEditor);
    menu_Help->addAction(action_AboutBox);
}

void MainWindow::makeConnections()
{
    connect(macroEditor, SIGNAL(visibilityChanged(bool)), action_MacroEditor, SLOT(setChecked(bool)));

    connect(action_Quit, SIGNAL(triggered(bool)), this, SLOT(close()));
    connect(action_MacroEditor, SIGNAL(triggered(bool)), macroEditor, SLOT(setVisible(bool)));
    connect(action_AboutBox, SIGNAL(triggered(bool)), this, SLOT(showAboutBox()));
}
