#include "lose.h"
#include "ui_lose.h"
#include "game.h"

#include <QLabel>
#include <QMovie>
#include <QDebug>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QGraphicsView>

extern QGraphicsView * view;
extern QMediaPlayer * music;
extern Game * game;

lose::lose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lose)
{
    ui->setupUi(this);
    ui->setupUi(this);
    QMovie *movie = new QMovie("../ANNigilator/images/lose.gif");
    if (movie->isValid() == false) {
        qDebug() << "Error";
        abort();
    }
    ui->label->setMovie(movie);
    movie->setScaledSize(QSize(this->width(), this->height()));
    movie->start();
    QMediaPlaylist * playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/lose.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer * local_music  = new QMediaPlayer();
    local_music->setPlaylist(playlist);
    local_music->play();
    game->close();
    view->close();
    music->stop();
    this->window()->setWindowTitle("YOU LOST");
}

lose::~lose()
{
    delete ui;
}
