#ifndef MACROEDITOR_H
#define MACROEDITOR_H

#include <QDockWidget>

#include "ui_macroeditor.h"
#include "textmacrowidget.h"

class MacroEditor : public QDockWidget, public Ui::MacroEditor
{
    Q_OBJECT

public:
    MacroEditor(QWidget *parent = 0);
    virtual ~MacroEditor();

private slots:
    void addMacroBox();
    void removeMacroBox();

    void macroTriggered(TextMacroWidget *source);

private:
    void initUi();
    void makeConnections();
};

#endif // MACROEDITOR_H
