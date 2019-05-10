#include "game.h"
#include "dialog.h"

#include <QGraphicsRectItem>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QTimer>

extern int score;

Game::Game(QWidget *parent)
{
    //creating scene
    qDebug() << "TUT";
    scene = new QGraphicsScene();
    // creating an item
    player = new Player();




    //put item on scene
    scene->addItem(player);

    //add progressBar

    bar = new QProgressBar();
    bar->setMaximum(100);
    bar->setMinimum(-100);
    bar->setOrientation(Qt::Orientation::Vertical);

    //set progressBar pos
    bar->move(800 - 30,0);
    bar->resize(30,600);
    bar->setValue(player->score);

    scene->addWidget(bar);

    //add bg
    scene->setBackgroundBrush(QBrush(QImage(":/images/images/other/bg_image.jpg").scaled(QSize(800,600))));


    //focus on item
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //add a view
    QGraphicsView *view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    player->setPos(view->width()/2-150,view->height()-250/*player->rect().height()-5*/);

    //spawn enemies
    Dialog dialog;
    if (!dialog.exec()) {
        abort();
    }
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(1000 - score*3);


    //play bg music in a loop
    QMediaPlaylist * playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/sounds/bg_music.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer * music  = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();

    view->show();

}

