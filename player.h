#ifndef PLAYER_H
#define PLAYER_H

//#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "bullet.h"
#include <QMessageBox>


class Player :public QGraphicsPixmapItem
{
public:
    Player();
    Bullet * bullet;
    void keyPressEvent(QKeyEvent * event);
    void increaseLife();
    void decreaseLife();
    int getLife();
    int life;
    QMessageBox *msg;

};

#endif // PLAYER_H

