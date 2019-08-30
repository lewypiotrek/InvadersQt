#ifndef ENEMY_H
#define ENEMY_H

//#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include "bullet.h"
#include <QObject>
#include <cstdlib>
#include <ctime>
#include <QGraphicsItem>

class Enemy :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy();
    void setIndex(unsigned int i);
public slots:
    void shoot();
private:
    Bullet * bullet;
    QTimer * timer;
    unsigned int index;


};

#endif // ENEMY_H
