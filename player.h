#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "QProgressBar"

class Player :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
    int score = -50;
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
};

#endif // MYRECT_H
