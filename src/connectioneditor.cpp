#include <QtGui>

#include "connectioneditor.h"

ConnectionEditor::ConnectionEditor(QWidget *parent)
    : QDockWidget(parent)
{
    setupUi(this);
}

ConnectionEditor::~ConnectionEditor()
{
}
