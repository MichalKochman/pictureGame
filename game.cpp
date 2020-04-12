#include "game.h"
#include "ui_game.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QKeyEvent>
#include <QScreen>
#include <QImageReader>
#include <string.h>


Game::Game(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Game)
    , scene(new QGraphicsScene)


{
    ui->setupUi(this);
    this->showFullScreen();
    ui->ImgDisplay->setGeometry(0,0,QGuiApplication::primaryScreen()->geometry().width(), QGuiApplication::primaryScreen()->geometry().height());
    ui->ImgDisplay->setAlignment(Qt::AlignLeft);


    //ui->ImgDisplay->fitInView()
    pickRandom();

}

Game::~Game()
{
    delete ui;
    delete scene;
}

void Game::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "MainWindow::keyPressEvent():" << event;

     if (event->key()== Qt::Key_Escape){
            QCoreApplication::exit(0);
     } else if (event->key() == currentKey) {
        qDebug()<<"Correct letter";
        pickRandom();
     } else {
         qDebug()<<"uknownCmd";
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
    QPixmap pixmap= QPixmap::fromImage(newImage);
    scene->addPixmap(pixmap.scaled(scene->width(), scene->height(), Qt::KeepAspectRatio));
    scene->setSceneRect(pixmap.rect());
    ui->ImgDisplay->setScene(scene);
}

/*!
 * \brief Game::pickRandom pics random Pictre, loads it and display it */
void Game::pickRandom(void){
    int tmp;
    do  {
    tmp = rand()%26;
    //qDebug()<<"Trying to locate picture " << QString(letters[tmp])<<".png";
    }
    while (!loadFile("img/" + QString(letters[tmp]) + ".png") || currentKey == (Qt::Key)letters[tmp] );
    qDebug()<<"Loaded picture " << QString(letters[tmp])<<".png";
    currentKey = (Qt::Key)letters[tmp];
    qDebug()<<"Current key = " <<currentKey;
}

