#include "pillar.h"

Pillar::Pillar(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/pillar.png"));
}
