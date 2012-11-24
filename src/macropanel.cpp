/*
 * This file is part of 'telamon'.
 *
 *    'telamon' is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    'telamon' is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with 'telamon'. If not, see <http://www.gnu.org/licenses/>.
 */

#include <QtGui>

#include "macropanel.h"

MacroPanel::MacroPanel(QWidget *parent)
    : QDockWidget(parent)
{
    setupUi(this);

    initUi();
    makeConnections();
}

MacroPanel::~MacroPanel()
{
}

void MacroPanel::initUi()
{
    QList<TextMacroWidget*> list = scrollAreaWidgetContents->findChildren<TextMacroWidget*>();

    if (list.count() < 1)
    {
        pushButton_Remove->setEnabled(false);
    }
}

void MacroPanel::makeConnections()
{
    connect(pushButton_Add, SIGNAL(clicked(bool)), this, SLOT(addMacroBox()));
    connect(pushButton_Remove, SIGNAL(clicked(bool)), this, SLOT(removeMacroBox()));
}

void MacroPanel::addMacroBox()
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

void MacroPanel::removeMacroBox()
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

void MacroPanel::macroTriggered(TextMacroWidget *source)
{
    qDebug() << "macroTriggered():" << source;
}
