#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QtMath>
#include "game.h"
#include "pillar.h"
#include <QDebug>

extern Game * game;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    qDebug() << "Bullet created.";
    setPos(game->player->x() + game->player->boundingRect().width() / 2, game->player->y());
    setRotation(game->player->rotation());
    Color color = static_cast<Color>(game->player->color);
    if      (color == BLUE)    setPixmap(QPixmap(":/images/bluebullet.png"   ));
    else if (color == BROWN)   setPixmap(QPixmap(":/images/brownbullet.png"  ));
    else if (color == CYAN)    setPixmap(QPixmap(":/images/cyanbullet.png"   ));
    else if (color == GREEN)   setPixmap(QPixmap(":/images/greenbullet.png"  ));
    else if (color == MAGENTA) setPixmap(QPixmap(":/images/magentabullet.png"));
    else if (color == ORANGE)  setPixmap(QPixmap(":/images/orangebullet.png" ));
    else if (color == PURPLE)  setPixmap(QPixmap(":/images/purplebullet.png" ));
    else if (color == RED)     setPixmap(QPixmap(":/images/redbullet.png"    ));
    else if (color == YELLOW)  setPixmap(QPixmap(":/images/yellowbullet.png" ));
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(30);
}

void Bullet::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++)
    {
        if (typeid(*(colliding_items[i])) == typeid(Pillar))
        {
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    if (rotation() >= 0 && rotation() <= 90) setPos(x() + velocity * qSin(qDegreesToRadians(rotation())), y() - velocity * qCos(qDegreesToRadians(rotation())));
    else if (rotation() > 90 && rotation() <= 180) setPos(x() + velocity * qSin(qDegreesToRadians(rotation())), y() + velocity * -qCos(qDegreesToRadians(rotation())));
    else if (rotation() > 180 && rotation() <= 270) setPos(x() - velocity * -qSin(qDegreesToRadians(rotation())), y() + velocity * -qCos(qDegreesToRadians(rotation())));
    else setPos(x() - velocity * -qSin(qDegreesToRadians(rotation())), y() - velocity * qCos(qDegreesToRadians(rotation())));

    if (pos().y() + boundingRect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }
    else if (pos().x() + boundingRect().width() < 0)
    {
        scene()->removeItem(this);
        delete this;
        return;
    }
    else if (pos().y() - boundingRect().height() > game->sceneRect().height())
    {
        scene()->removeItem(this);
        delete this;
        return;
    }
    else if (pos().y() - boundingRect().width() > game->sceneRect().width())
    {
        scene()->removeItem(this);
        delete this;
        return;
    }
}
