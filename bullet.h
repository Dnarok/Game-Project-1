#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Bullet: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    enum Color {
        BLUE,
        BROWN,
        CYAN,
        GREEN,
        MAGENTA,
        ORANGE,
        PURPLE,
        RED,
        YELLOW
    };
    Color color;
    Bullet(QGraphicsItem * parent=0);
    qreal velocity {12.5};
public slots:
    void move();
};

#endif // BULLET_H
