#include <QtGui>

#include "textmacrowidget.h"

TextMacroWidget::TextMacroWidget(QWidget *parent)
    : QWidget(parent)
{
    setupUi(this);

    makeConnections();
}

TextMacroWidget::~TextMacroWidget()
{
}

void TextMacroWidget::makeConnections()
{
    connect(pushButton_Send, SIGNAL(clicked(bool)), this, SLOT(triggerCatched()));
}

void TextMacroWidget::triggerCatched()
{
    emit macroTriggered(this);
}
