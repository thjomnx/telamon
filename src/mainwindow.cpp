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
    action_LocalEndpointPanel->trigger();
    //action_RemoteEndpointPanel->trigger();
    //action_MacroPanel->trigger();
#endif
}

MainWindow::~MainWindow()
{
    delete macroPanel;
    delete remoteEndpointPanel;
    delete localEndpointPanel;
}

void MainWindow::showAboutBox()
{
    QString infoText = tr("There isn't so much yet ...");
    QMessageBox::about(this, tr("About Telamon"), infoText);
}

void MainWindow::createChilds()
{
    localEndpointPanel = new LocalEndpointPanel(this);
    localEndpointPanel->hide();

    remoteEndpointPanel = new RemoteEndpointPanel(this);
    remoteEndpointPanel->hide();

    macroPanel = new MacroPanel(this);
    macroPanel->hide();
}

void MainWindow::createActions()
{
    action_Quit = new QAction(tr("&Quit"), this);
    action_Quit->setShortcut(QKeySequence::Quit);
    action_Quit->setStatusTip(tr("Terminate all sessions and quit the application"));

    action_LocalEndpointPanel = new QAction(tr("&Local Endpoints"), this);
    action_LocalEndpointPanel->setCheckable(true);
    action_LocalEndpointPanel->setShortcut(tr("Ctrl+C"));
    action_LocalEndpointPanel->setStatusTip(tr("Show or hide the panel for local endpoints"));

    action_RemoteEndpointPanel = new QAction(tr("&Remote Endpoints"), this);
    action_RemoteEndpointPanel->setCheckable(true);
    action_RemoteEndpointPanel->setShortcut(tr("Ctrl+R"));
    action_RemoteEndpointPanel->setStatusTip(tr("Show or hide the panel for remote endpoints"));

    action_MacroPanel = new QAction(tr("&Macros"), this);
    action_MacroPanel->setCheckable(true);
    action_MacroPanel->setShortcut(tr("Ctrl+M"));
    action_MacroPanel->setStatusTip(tr("Show or hide the macro panel"));

    action_AboutBox = new QAction(tr("&About"), this);
    action_AboutBox->setStatusTip(tr("Show some infos about this application"));
}

void MainWindow::createMenus()
{
    menu_File->addAction(action_Quit);

    menu_View->addAction(action_LocalEndpointPanel);
    menu_View->addAction(action_RemoteEndpointPanel);
    menu_View->addAction(action_MacroPanel);

    menu_Help->addAction(action_AboutBox);
}

void MainWindow::makeConnections()
{
    connect(localEndpointPanel, SIGNAL(visibilityChanged(bool)), action_LocalEndpointPanel, SLOT(setChecked(bool)));
    connect(remoteEndpointPanel, SIGNAL(visibilityChanged(bool)), action_RemoteEndpointPanel, SLOT(setChecked(bool)));
    connect(macroPanel, SIGNAL(visibilityChanged(bool)), action_MacroPanel, SLOT(setChecked(bool)));

    connect(action_Quit, SIGNAL(triggered(bool)), this, SLOT(close()));
    connect(action_LocalEndpointPanel, SIGNAL(triggered(bool)), localEndpointPanel, SLOT(setVisible(bool)));
    connect(action_RemoteEndpointPanel, SIGNAL(triggered(bool)), remoteEndpointPanel, SLOT(setVisible(bool)));
    connect(action_MacroPanel, SIGNAL(triggered(bool)), macroPanel, SLOT(setVisible(bool)));
    connect(action_AboutBox, SIGNAL(triggered(bool)), this, SLOT(showAboutBox()));
}
