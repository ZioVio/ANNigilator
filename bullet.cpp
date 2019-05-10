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
           if (game->player->score >= 100) {
//               QMovie *movie = new QMovie("qrc:/images/images/win.gif");
//               if (!movie->isValid())
//                   {
//                    qDebug() << "PIZDA";
//                   }
//               QLabel *processLabel = new QLabel(game);
//               processLabel->resize(800, 600);
//               processLabel->setMovie(movie);
//               game->scene->addWidget(processLabel);
//               processLabel->raise();
//               movie->start();
               win dialog;
               dialog.exec();
               abort();
//               scene()->addPixmap(QPixmap(":/images/images/win.gif").scaled(QSize(800,600)));
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
