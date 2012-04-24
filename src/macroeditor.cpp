#include <QtGui>

#include "macroeditor.h"

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
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(new QLineEdit);
    layout->addWidget(new QPushButton);

    verticalLayout->removeItem(verticalSpacer);
    verticalLayout->addLayout(layout);
    verticalLayout->addSpacerItem(verticalSpacer);
}

void MacroEditor::removeMacroBox()
{
}
