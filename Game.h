/*
 * Game.h
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

#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "letterimage.h"
#include "infowidget.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Game; }
QT_END_NAMESPACE

class Game : public QMainWindow
{
    Q_OBJECT

public:
    Game(QWidget *parent = nullptr);
    ~Game();

private:
    enum State {BOOT, PLAY,AWAITING_START, ERROR, NO_LICENCE};
    Ui::Game *ui;
    void keyPressEvent(QKeyEvent *event);
    void loadPicture(void);
    bool loadFile(const QString &);
    void setImage(const QImage &newImage);
    void pickRandom(void);
    void startTheGame(void);
    void setGameLayout(void);
    void loadKeys(void);
    void setInfoText(void);
    bool checkLicenceFile(void);

    QGraphicsScene *scene;


    std::vector<letterImage> letters;
    Qt::Key currentKey;
    int numOfKeys;
    int countScore;
    State state;


};
#endif // GAME_H


