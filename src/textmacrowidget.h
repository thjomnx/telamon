#ifndef TEXTMACROWIDGET_H
#define TEXTMACROWIDGET_H

#include <QWidget>

#include "ui_textmacrowidget.h"

class TextMacroWidget : public QWidget, public Ui::TextMacroWidget
{
    Q_OBJECT

public:
    explicit TextMacroWidget(QWidget *parent = 0);
    virtual ~TextMacroWidget();

signals:
    void macroTriggered(TextMacroWidget* source);

private:
    void makeConnections();

private slots:
    void triggerCatched();
};

#endif // TEXTMACROWIDGET_H
