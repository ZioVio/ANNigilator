
#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include <QKeyEvent>
#include <QGraphicsScene>


Player::Player()
{
    setPixmap(QPixmap(":images/player1.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        if(pos().x()>-120)
        setPos(x()-10,y());
        setPixmap(QPixmap(":images/player1.png"));
    }else if(event->key() == Qt::Key_Right)
    {
        if(pos().x()+200<800)
        setPos(x()+10,y());
        setPixmap(QPixmap(":images/player1.png"));
    }/*else if(event->key() == Qt::Key_Up)
    {
        setPos(x(),y()-10);
    }else if(event->key() == Qt::Key_Down)
    {
        setPos(x(),y()+10);
    }*/else if(event->key() == Qt::Key_Space)
    {
        //create a bullet
        setPixmap(QPixmap(":images/player1shooting.png"));


        Bullet * bullet = new Bullet;
        bullet->setPos(x()+143,y()+177);
        scene()->addItem(bullet);
        Bullet * bullet2 = new Bullet;
        bullet2->setPos(x()+173,y()+183);
        scene()->addItem(bullet2);


    }
}

void Player::spawn()
{
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

