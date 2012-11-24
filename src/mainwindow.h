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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ui_mainwindow.h"
#include "localendpointpanel.h"
#include "remoteendpointpanel.h"
#include "macropanel.h"

class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow();
    virtual ~MainWindow();

private slots:
    void showAboutBox();

private:
    void createChilds();
    void createActions();
    void createMenus();

    void makeConnections();

    LocalEndpointPanel *localEndpointPanel;
    RemoteEndpointPanel *remoteEndpointPanel;
    MacroPanel *macroPanel;

    QAction *action_Quit;
    QAction *action_LocalEndpointPanel;
    QAction *action_RemoteEndpointPanel;
    QAction *action_MacroPanel;
    QAction *action_AboutBox;
};

#endif // MAINWINDOW_H
