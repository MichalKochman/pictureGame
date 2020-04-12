


#include <QApplication>

#include "game.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QGuiApplication::setApplicationDisplayName(Game::tr("Game"));
    Game game;;
    game.show();
    return app.exec();
}
