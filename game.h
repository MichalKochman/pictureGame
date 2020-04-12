#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QGraphicsScene>


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
    Ui::Game *ui;
    void keyPressEvent(QKeyEvent *event);
    void loadPicture(void);
    bool loadFile(const QString &);
    void setImage(const QImage &newImage);
    void pickRandom(void);


    QGraphicsScene *scene;

    char letters[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    Qt::Key currentKey;


};
#endif // GAME_H


