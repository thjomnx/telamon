#ifndef TEXTMACROWIDGET_H
#define TEXTMACROWIDGET_H

#include <QWidget>

#include "ui_textmacrowidget.h"

class TextMacroWidget : public QWidget, public Ui::TextMacroWidget
{
    Q_OBJECT

public:
    TextMacroWidget(QWidget *parent = 0);
    virtual ~TextMacroWidget();
};

#endif // TEXTMACROWIDGET_H
