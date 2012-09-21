/**
 * This file is part of 'telamon'.
 *
 *    'telamon' is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    'telamon' is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with 'telamon'. If not, see <http://www.gnu.org/licenses/>.
 */

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
    //action_RemoteViewer->trigger();
    //action_MacroEditor->trigger();
#endif
}

MainWindow::~MainWindow()
{
    delete macroEditor;
    delete remoteViewer;
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

    remoteViewer = new RemoteViewer(this);
    remoteViewer->hide();

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

    action_RemoteViewer = new QAction(tr("&Remote Viewer"), this);
    action_RemoteViewer->setCheckable(true);
    action_RemoteViewer->setShortcut(tr("Ctrl+R"));
    action_RemoteViewer->setStatusTip(tr("Show or hide the remote viewer"));

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
    menu_View->addAction(action_RemoteViewer);
    menu_View->addAction(action_MacroEditor);

    menu_Help->addAction(action_AboutBox);
}

void MainWindow::makeConnections()
{
    connect(connectionEditor, SIGNAL(visibilityChanged(bool)), action_ConnectionEditor, SLOT(setChecked(bool)));
    connect(remoteViewer, SIGNAL(visibilityChanged(bool)), action_RemoteViewer, SLOT(setChecked(bool)));
    connect(macroEditor, SIGNAL(visibilityChanged(bool)), action_MacroEditor, SLOT(setChecked(bool)));

    connect(action_Quit, SIGNAL(triggered(bool)), this, SLOT(close()));
    connect(action_ConnectionEditor, SIGNAL(triggered(bool)), connectionEditor, SLOT(setVisible(bool)));
    connect(action_RemoteViewer, SIGNAL(triggered(bool)), remoteViewer, SLOT(setVisible(bool)));
    connect(action_MacroEditor, SIGNAL(triggered(bool)), macroEditor, SLOT(setVisible(bool)));
    connect(action_AboutBox, SIGNAL(triggered(bool)), this, SLOT(showAboutBox()));
}
