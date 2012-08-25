#ifndef MULTIFORMATLINEEDIT_H
#define MULTIFORMATLINEEDIT_H

#include <QLineEdit>

class MultiFormatLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    explicit MultiFormatLineEdit(QWidget *parent = 0);
    MultiFormatLineEdit(const QString& , QWidget *parent = 0);
};

#endif // MULTIFORMATLINEEDIT_H
