#include "win.h"
#include "ui_win.h"
#include <QLabel>
#include <QMovie>
#include <QDebug>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QGraphicsView>

extern QGraphicsView * view;
extern QMediaPlayer * music;

win::win(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::win)
{
    ui->setupUi(this);
    QMovie *movie = new QMovie("../ANNigilator/images/win.gif");
    if (movie->isValid() == false) {
        qDebug() << "Error";
        abort();
    }
    ui->label->setMovie(movie);
    movie->setScaledSize(QSize(this->width(), this->height()));
    movie->start();
    QMediaPlaylist * playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sounds/sounds/win.wav"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer * local_music  = new QMediaPlayer();
    local_music->setPlaylist(playlist);
    local_music->play();
    view->close();
    music->stop();
    this->window()->setWindowTitle("YOU WON!");
}

win::~win()
{
    delete ui;
}
