#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ui_mainwindow.h"
#include "macroeditor.h"

class QAction;

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

    MacroEditor *macroEditor;

    QAction *action_Quit;
    QAction *action_MacroEditor;
    QAction *action_AboutBox;
};

#endif // MAINWINDOW_H
