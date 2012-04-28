#include <QtGui>

#include "macroeditor.h"
#include "textmacrowidget.h"

MacroEditor::MacroEditor(QWidget *parent)
    : QDockWidget(parent)
{
    setupUi(this);

    initUi();
    makeConnections();
}

MacroEditor::~MacroEditor()
{
}

void MacroEditor::initUi()
{
    QList<TextMacroWidget*> list = dockWidgetContents->findChildren<TextMacroWidget*>();

    if (list.count() < 1)
    {
        pushButton_Remove->setEnabled(false);
    }
}

void MacroEditor::makeConnections()
{
    connect(pushButton_Add, SIGNAL(clicked(bool)), this, SLOT(addMacroBox()));
    connect(pushButton_Remove, SIGNAL(clicked(bool)), this, SLOT(removeMacroBox()));
}

void MacroEditor::addMacroBox()
{
    QList<TextMacroWidget*> list = dockWidgetContents->findChildren<TextMacroWidget*>();
    TextMacroWidget *tmw = new TextMacroWidget(this);

    qDebug() << "addMacroBox() " << tmw;

    verticalLayout->insertWidget(list.count() + 1, tmw);

    if (list.count() == 0)
    {
        pushButton_Remove->setEnabled(true);
    }
}

void MacroEditor::removeMacroBox()
{
    QList<TextMacroWidget*> list = dockWidgetContents->findChildren<TextMacroWidget*>();

    if (list.count() == 1)
    {
        pushButton_Remove->setEnabled(false);
    }

    if (!list.empty())
    {
        TextMacroWidget *tmw = list.last();

        qDebug() << "removeMacroBox() " << tmw;

        verticalLayout->removeWidget(tmw);
        delete tmw;
    }
}
