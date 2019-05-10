
#include "enemy.h"
#include "player.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <cstdlib>
#include "game.h"

extern Game * game;

extern int score;

Enemy::Enemy()
{
    //drew the rect
    srand(time(0));
    int randEnemy = rand() % 6 + 1;
    int randEnemyPos = rand() % 700 + 1;

    setPos(randEnemyPos,0);


    setPixmap(QPixmap(":/images/images/enemies/enemy"+ QString::number(randEnemy) +".png").scaled(QSize(100,100)));


    //connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(300);
}


void Enemy::move()
{
    setPos(x(),y()+10 + (float)score/10);
    qDebug() << score;
    if(pos().y() + 100 > 600)
    {
        game->player->score -= 10;
        game->bar->setValue(game->player->score);
        scene()->removeItem(this);
        delete this;
    }
}
