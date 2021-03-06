/*
 * infowidget.h
 *
 * Copyright 2020 Michal Kochman <michalkochman@email.cz>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */
#ifndef INFOWIDGET_H
#define INFOWIDGET_H

#include <QWidget>
#include "ui_infowidget.h"
namespace Ui {
class infoWidget;
}

class infoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit infoWidget(QWidget *parent = nullptr);
    ~infoWidget();
    void setTextWelcome();
    void setTextNoImg();

private:
    Ui::infoWidget *ui;
    void setFrame(void);
    void setLayout(void);
    void setSplitter(int middleY, int startX, int endX);

};

#endif // INFOWIDGET_H
