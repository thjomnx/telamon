#include <QtGui>

#include "mainwindow.h"

#define DEBUG

MainWindow::MainWindow()
    : QMainWindow()
{
    setupUi(this);

    createChilds();
    createActions();
    createMenus();

    makeConnections();

#ifdef DEBUG
    action_ConnectionEditor->trigger();
    //action_MacroEditor->trigger();
#endif
}

MainWindow::~MainWindow()
{
    delete macroEditor;
    delete connectionEditor;
}

void MainWindow::showAboutBox()
{
    QString infoText = tr("There isn't so much yet ...");
    QMessageBox::about(this, tr("About Telamon"), infoText);
}

void MainWindow::createChilds()
{
    connectionEditor = new ConnectionEditor(this);
    connectionEditor->hide();

    macroEditor = new MacroEditor(this);
    macroEditor->hide();
}

void MainWindow::createActions()
{
    action_Quit = new QAction(tr("&Quit"), this);
    action_Quit->setShortcut(QKeySequence::Quit);
    action_Quit->setStatusTip(tr("Terminate all sessions and quit the application"));

    action_ConnectionEditor = new QAction(tr("&Connection Editor"), this);
    action_ConnectionEditor->setCheckable(true);
    action_ConnectionEditor->setShortcut(tr("Ctrl+C"));
    action_ConnectionEditor->setStatusTip(tr("Show or hide the connection editor"));

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

    menu_View->addAction(action_ConnectionEditor);
    menu_View->addAction(action_MacroEditor);

    menu_Help->addAction(action_AboutBox);
}

void MainWindow::makeConnections()
{
    connect(macroEditor, SIGNAL(visibilityChanged(bool)), action_MacroEditor, SLOT(setChecked(bool)));

    connect(action_Quit, SIGNAL(triggered(bool)), this, SLOT(close()));
    connect(action_ConnectionEditor, SIGNAL(triggered(bool)), connectionEditor, SLOT(setVisible(bool)));
    connect(action_MacroEditor, SIGNAL(triggered(bool)), macroEditor, SLOT(setVisible(bool)));
    connect(action_AboutBox, SIGNAL(triggered(bool)), this, SLOT(showAboutBox()));
}
