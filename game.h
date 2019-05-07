//#ifndef GAME_H
//#define GAME_H


#include <QGraphicsScene>
#include <QGraphicsView>
#include <QProgressBar>
#include <QWidget>
#include "player.h"
#include "bullet.h"


class Game: public QGraphicsView
{
public:
    Game(QWidget * parent  = nullptr);

    QGraphicsScene * scene;
    Player * player;
    QProgressBar * bar;



};

//#endif // GAME_H
