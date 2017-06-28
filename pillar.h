#ifndef PILLAR_H
#define PILLAR_H

#include "myrect.h"
#include <QList>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Pillar: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Pillar(QGraphicsItem * parent=0);
};

#endif // PILLAR_H
