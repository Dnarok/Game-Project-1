#include "myrect.h"
#include "pillar.h"
#include "bullet.h"
#include <QKeyEvent>
#include <QTimer>
#include <QtMath>
#include <QDebug>
#include <QList>
#include "game.h"

extern Game * game;

myRect::myRect(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    randomizeShip();
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(rotate()));
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(30);
}

void myRect::keyPressEvent(QKeyEvent *event) {
    switch (event->key())
    {
        case Qt::Key_B :
            randomizeShip();
            break;
        case Qt::Key_Up :
            isMovingForward = true;
            break;
        case Qt::Key_A :
            setTransformOriginPoint(this->boundingRect().x() + this->boundingRect().width() / 2, this->boundingRect().y() + this->boundingRect().height() / 2);
            break;
        case Qt::Key_S :
            setTransformOriginPoint(this->boundingRect().x() + this->boundingRect().width() / 2, this->boundingRect().height());
            break;
        case Qt::Key_D :
            setTransformOriginPoint(this->boundingRect().x() + this->boundingRect().width() / 2, this->boundingRect().y());
            break;
        case Qt::Key_F :
            setTransformOriginPoint(this->boundingRect().x(), this->boundingRect().y());
            break;
        case Qt::Key_Left :
            isRotatingLeft = true;
            isRotatingRight = false;
            break;
        case Qt::Key_Right :
            isRotatingLeft = false;
            isRotatingRight = true;
            break;
        case Qt::Key_Space :
            Bullet * bullet = new Bullet();
            scene()->addItem(bullet);
    }
}

void myRect::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt:: Key_Up :
            isMovingForward = false;
            break;
        case Qt::Key_Left :
            isRotatingLeft = false;
            break;
        case Qt::Key_Right :
            isRotatingRight = false;
            break;
    }
}

void myRect::move()
{
    /* QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if (typeid(*(colliding_items[i])) == typeid(Pillar))
        {
            if ()
            {

            }
        }
    } */
    if (isMovingForward) {
    if (rotation() >= 0 && rotation() <= 90) setPos(x() + velocity * qSin(qDegreesToRadians(rotation())), y() - velocity * qCos(qDegreesToRadians(rotation())));
    else if (rotation() > 90 && rotation() <= 180) setPos(x() + velocity * qSin(qDegreesToRadians(rotation())), y() + velocity * -qCos(qDegreesToRadians(rotation())));
    else if (rotation() > 180 && rotation() <= 270) setPos(x() - velocity * -qSin(qDegreesToRadians(rotation())), y() + velocity * -qCos(qDegreesToRadians(rotation())));
    else setPos(x() - velocity * -qSin(qDegreesToRadians(rotation())), y() - velocity * qCos(qDegreesToRadians(rotation())));
    }
}

void randomizeShip()
{
    color = static_cast<Color>(QTime::currentTime().msec() % 9);
    if      (color == BLUE)    setPixmap(QPixmap(":/images/blueship.png"   ));
    else if (color == BROWN)   setPixmap(QPixmap(":/images/brownship.png"  ));
    else if (color == CYAN)    setPixmap(QPixmap(":/images/cyanship.png"   ));
    else if (color == GREEN)   setPixmap(QPixmap(":/images/greenship.png"  ));
    else if (color == MAGENTA) setPixmap(QPixmap(":/images/magentaship.png"));
    else if (color == ORANGE)  setPixmap(QPixmap(":/images/orangeship.png" ));
    else if (color == PURPLE)  setPixmap(QPixmap(":/images/purpleship.png" ));
    else if (color == RED)     setPixmap(QPixmap(":/images/redship.png"    ));
    else if (color == YELLOW)  setPixmap(QPixmap(":/images/yellowship.png" ));
}

void myRect::rotate()
{
    if (isRotatingLeft) omega -= alpha;
    else if (isRotatingRight) omega += alpha;
    if (omega > maxOmega + alpha2) omega = maxOmega + alpha2;
    else if (omega < -maxOmega - alpha2) omega = -maxOmega - alpha2;
    setRotation(rotation() + omega);
    if (omega == 0) omega = 0;
    else if (omega >= alpha2) omega -= alpha2;
    else if (omega <= -alpha2) omega += alpha2;
    else if (omega > 0 && omega < alpha2) omega = 0;
    else if (omega < 0 && omega > -alpha2) omega = 0;
}
