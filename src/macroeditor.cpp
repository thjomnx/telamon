#include <QtGui>

#include "macroeditor.h"

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
    QList<TextMacroWidget*> list = scrollAreaWidgetContents->findChildren<TextMacroWidget*>();

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
    QList<TextMacroWidget*> list = scrollAreaWidgetContents->findChildren<TextMacroWidget*>();
    TextMacroWidget *tmw = new TextMacroWidget(this);

    connect(tmw, SIGNAL(macroTriggered(TextMacroWidget*)), this, SLOT(macroTriggered(TextMacroWidget*)));

    qDebug() << "addMacroBox():" << tmw;

    QBoxLayout* layout = static_cast<QBoxLayout*>(scrollAreaWidgetContents->layout());
    layout->insertWidget(list.count(), tmw);

    if (list.count() == 0)
    {
        pushButton_Remove->setEnabled(true);
    }
}

void MacroEditor::removeMacroBox()
{
    QList<TextMacroWidget*> list = scrollAreaWidgetContents->findChildren<TextMacroWidget*>();

    if (list.count() == 1)
    {
        pushButton_Remove->setEnabled(false);
    }

    if (!list.empty())
    {
        TextMacroWidget *tmw = list.last();

        disconnect(tmw, SIGNAL(macroTriggered(TextMacroWidget*)), this, SLOT(macroTriggered(TextMacroWidget*)));

        qDebug() << "removeMacroBox():" << tmw;

        QLayout* layout = static_cast<QLayout*>(scrollAreaWidgetContents->layout());
        layout->removeWidget(tmw);

        delete tmw;
    }
}

void MacroEditor::macroTriggered(TextMacroWidget *source)
{
    qDebug() << "macroTriggered():" << source;
}
