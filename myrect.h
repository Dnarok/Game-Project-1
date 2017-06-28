#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTime>
#include <QGraphicsItem>

class myRect: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *event);

    myRect(QGraphicsItem * parent=0);
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
    qreal alpha {1};
    qreal omega {0};
    qreal const maxOmega {10};
    qreal alpha2 {.25};
    qreal velocity {10};
    bool isRotatingLeft  {false};
    bool isRotatingRight {false};
    bool isMovingForward {false};
    friend void randomizeShip();
public slots:
    void rotate();
    void move();
};

#endif // MYRECT_H
