#include "bullet.h"
#include "player.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include "game.h"

extern Game * game;

Bullet::Bullet()
{
    //drew the rect
    setPixmap(QPixmap(":/images/bullet.png"));

    //connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}


void Bullet::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0,n = colliding_items.size();i<n;++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Enemy))
        {
           scene()->removeItem(colliding_items[i]);
           scene()->removeItem(this);

           game->player->score +=10;
           game->bar->setValue(game->player->score);

           delete colliding_items[i];
           delete this;
           return;
        }
    }


    setPos(x(),y()-10);
    if(pos().y() + 5 < 0)
    {
        scene()->removeItem(this);

        delete this;
    }
}
