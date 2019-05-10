#include "win.h"
#include "ui_win.h"
#include <QLabel>
#include <QMovie>
#include <QDebug>

win::win(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::win)
{
    ui->setupUi(this);
//    QMovie *movie = new QMovie(":/images/images/win.gif");

//    ui->label->setMovie(movie);
//    movie->start();


//    QMovie *movie = new QMovie(":/images/images/win.gif");
//    if (!movie->isValid())
//    {
//        qDebug() << "PIZDA";
//    }
//    QLabel *processLabel = new QLabel(this);
//    processLabel->setMovie(movie);
//    movie->start();
    QMovie *movie = new QMovie(":/images/images/win.gif");
    QLabel *yourLabel = new QLabel(this);
    yourLabel->setMovie(movie);
    movie->start();
//    QMovie mo;
//    double m;
//    QPixmap pix(":/images/images/win.gif");
//        m = double(pix.width())/pix.height();
//        mo.setFileName(":/ico/loader.gif");
//        mo.setSpeed(ui->label->value());
//        setSizeMovie(ui->spinBox_2->value());
//        ui->label->setMovie(&mo);
//        mo.start();
//        connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(setSpeedMovie(int)));
//        connect(ui->spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(setSizeMovie(int)));
}

win::~win()
{
    delete ui;
}
