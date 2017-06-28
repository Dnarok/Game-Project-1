#ifndef GAME_H
#define GAME_H

#include "myrect.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

class Game: public QGraphicsView
{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    myRect * player;

};

#endif // GAME_H
