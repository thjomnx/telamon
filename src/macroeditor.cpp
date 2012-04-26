#include <QtGui>

#include "macroeditor.h"
#include "textmacrowidget.h"

MacroEditor::MacroEditor(QWidget *parent)
    : QDockWidget(parent)
{
    setupUi(this);

    makeConnections();
}

MacroEditor::~MacroEditor()
{
}

void MacroEditor::makeConnections()
{
    connect(pushButton_Add, SIGNAL(clicked(bool)), this, SLOT(addMacroBox()));
    connect(pushButton_Remove, SIGNAL(clicked(bool)), this, SLOT(removeMacroBox()));
}

void MacroEditor::addMacroBox()
{
    TextMacroWidget *tmw = new TextMacroWidget(this);
    int idx = verticalLayout->count() - 2;

    qDebug() << tmw;

    verticalLayout->insertWidget(idx + 1, tmw);
}

void MacroEditor::removeMacroBox()
{
    QList<TextMacroWidget*> list = dockWidgetContents->findChildren<TextMacroWidget*>();

    if (!list.empty())
    {
        TextMacroWidget *tmw = list.last();

        qDebug() << tmw;

        verticalLayout->removeWidget(tmw);
        delete tmw;
    }
}
