#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ui_mainwindow.h"

class QAction;

class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void about();

private:
    void createActions();
    void createMenus();

    void makeConnections();

    QAction *quitAction;
    QAction *aboutAction;
};

#endif // MAINWINDOW_H
