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
    enum State {BOOT, PLAY,AWAITING_START, ERROR};
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

    QGraphicsScene *scene;
    //infoWidget *info;


    std::vector<letterImage> letters;
    Qt::Key currentKey;
    int numOfKeys;
    int countScore;
    State state;


};
#endif // GAME_H


