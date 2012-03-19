#include <QtGui>

#include "multiformatlineedit.h"

MultiFormatLineEdit::MultiFormatLineEdit(QWidget *parent)
{
    MultiFormatLineEdit("", parent);
}

MultiFormatLineEdit::MultiFormatLineEdit(const QString& contents, QWidget *parent)
    : QLineEdit(parent)
{
    setText(contents);
}
