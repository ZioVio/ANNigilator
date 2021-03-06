#include "bullet.h"
#include "player.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QLabel>
#include <QMovie>
#include <QList>
#include "game.h"
#include "win.h"
#include "lose.h"

extern Game * game;

extern int score;

Bullet::Bullet()
{
    //drew the rect
    setPixmap(QPixmap(":/images/images/other/bullet.png"));

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
           score = game->player->score;
           game->bar->setValue(game->player->score);
           static bool flag = false;
           if (game->player->score >= 200 && !flag) {
               flag = true;
               win dialog;
               dialog.exec();
               game->setHidden(true);
//               game->window()->close();
           }
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
