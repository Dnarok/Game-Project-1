#include "game.h"
#include "pillar.h"
#include <QTimer>
#include <QBrush>
#include <QImage>

Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 800);
    setBackgroundBrush(QBrush(QImage(":/images/bgneutral.png")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,800);

    player = new myRect();
    player->setPos(22.5, 760);
    player->setRotation(45);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    Pillar * pillar  = new Pillar();
    pillar->setRotation(45);
    Pillar * pillar2 = new Pillar();
    pillar2->setRotation(45);
    Pillar * pillar3 = new Pillar();
    pillar3->setRotation(45);
    Pillar * pillar4 = new Pillar();
    pillar4->setRotation(45);

    pillar->setPos(200,200);
    pillar2->setPos(200,600);
    pillar3->setPos(600,200);
    pillar4->setPos(600,600);

    scene->addItem(pillar); scene->addItem(pillar2); scene->addItem(pillar3); scene->addItem(pillar4);
    show();
}
