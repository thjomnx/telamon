#include <QtGui>

#include "macroeditor.h"

MacroEditor::MacroEditor(QWidget* parent)
    : QDockWidget(parent)
{
    setupUi(this);
}

MacroEditor::~MacroEditor()
{
}
