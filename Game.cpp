/*
 * Game.cpp
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

#include "Game.h"
#include "ui_Game.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QKeyEvent>
#include <QScreen>
#include <QImageReader>
#include <string.h>
#include "letterimage.h"
#include "infowidget.h"


Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
    , scene(new QGraphicsScene)
    //, info (new infoWidget)


{
    state = State::BOOT;
    ui->setupUi(this);
    setGameLayout();
    ui->scoreBoard->hide();
    ui->ImgDisplay->hide();
    ui->licencetext->hide();
    //info->show();
    loadKeys();
    //this->setCentralWidget(info);
    setInfoText();
    countScore = 0;



}

Game::~Game()
{
    delete ui;
    delete scene;
}

void Game::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "Game::keyPressEvent():" << event;

     if (event->key()== Qt::Key_Escape){
         if (state == State::AWAITING_START){
            QCoreApplication::exit(0);
         } else {
             state = State::AWAITING_START;
             ui->infopanel->setTextWelcome();
             ui->infopanel->show();
             ui->ImgDisplay->hide();
         }
     } else if (state == State::AWAITING_START){
         startTheGame();
     } else if (event->key() == currentKey) {
        qDebug()<<"Correct letter";
        pickRandom();
        ui->scoreBoard->setText("Score: " + QString::number(++countScore));
     } else {
         qDebug()<<"uknownCmd";
         ui->scoreBoard->setText("Score: " + QString::number(--countScore));
     }
}

/*!
 * \brief Game::loadFile loads image
 * \param fileName relative path to image
 * \return true on succes, false otherwise
 */
bool Game::loadFile(const QString &fileName)
{
    QImageReader reader(fileName);
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();
    if (newImage.isNull()) {
        return false;
    }

    setImage(newImage);

    return true;
}
/*!
 * \brief Game::setImage display newImage on screen. Suppose that when making this morel low-level, all img will have the correct size by default and no resizing will be done.
 * \param newImage QImage
 */
void Game::setImage(const QImage &newImage)
{   qDebug()<<__PRETTY_FUNCTION__;
    scene->clear();
    QPixmap pixmap= QPixmap::fromImage(newImage).scaled(ui->centralwidget->size(), Qt::KeepAspectRatio);
    if (pixmap.isNull()){
        //perhaps the pixmap was wrongly scaled?
        qDebug()<<__PRETTY_FUNCTION__<<" Null pixmap";
        QPixmap pixmap= QPixmap::fromImage(newImage);
    }
    scene->addPixmap(pixmap);
    scene->setSceneRect(pixmap.rect());
    ui->ImgDisplay->setScene(scene);
}

/*!
 * \brief Game::pickRandom pics random Pictre, loads it and display it */
void Game::pickRandom(void){
   int tmp, maxcount=0;
    do  {
        tmp = rand()%numOfKeys;
        if (maxcount++ > 100000){
            qWarning()<<"Is the path set?";
        }
    }
    while (!letters[tmp].haveImages() ||  currentKey == letters[tmp].getKey());
    setImage(letters[tmp].getRandomImage());
    currentKey = letters[tmp].getKey();
    qDebug() << "Waiting for key: "<<currentKey;
}

void Game::startTheGame(void){
  state = State::PLAY;


  pickRandom();
  countScore=0;
  ui->scoreBoard->setText("Score: 0");
  qDebug()<<"GameStarted";

  ui->infopanel->hide();
  ui->ImgDisplay->show();
  ui->scoreBoard->show();

}


void Game::setGameLayout(){
    this->showFullScreen();
    int w = QGuiApplication::primaryScreen()->geometry().width();
    int h = QGuiApplication::primaryScreen()->geometry().height();
    ui->ImgDisplay->setGeometry(0,0,w,h);
    ui->ImgDisplay->setAlignment(Qt::AlignCenter);
    ui->infopanel->setGeometry(w/2-250,h/2-250,500,500);
    ui->scoreBoard->setGeometry(5,5,200,20);
}

void Game::loadKeys(void){
    for (char c = 'A'; c<='Z'; c++){
       letterImage letter(c);
       if (letter.haveImages()){
            letters.push_back(letter);
       }
    }
    numOfKeys = letters.size();
    letters.shrink_to_fit();
    qDebug()<<__PRETTY_FUNCTION__<<"numOfKeys = " <<numOfKeys;
}


void Game::setInfoText(void){
    if (numOfKeys>0){
      ui->infopanel->setTextWelcome();
        state = State::AWAITING_START;
    }else{
       ui->infopanel->setTextNoImg();
        state = State::ERROR;
        qWarning()<<"NO IMAGES FOUND";
    }

}

