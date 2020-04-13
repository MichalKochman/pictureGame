


#include <QApplication>
#include <QtDebug>
#include "Game.h"
#include "licenceinfo.h"

int main(int argc, char *argv[])
{
    qInfo() <<licenceInfo().copyright;
    qInfo() <<licenceInfo().waranty;
    qInfo() <<licenceInfo().licence;
    qInfo() <<licenceInfo().QtInfo;

    QApplication app(argc, argv);
    QGuiApplication::setApplicationDisplayName(Game::tr("Game"));
    Game game;;
    game.show();
    return app.exec();
}
