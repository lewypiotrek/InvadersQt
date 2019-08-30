#include "bullet.h"
#include "game.h"
#include <QList>
#include <QDebug>

extern Game * game;

Bullet::Bullet()
{
    //setRect(0,0,10,50);
    setPixmap(QPixmap(":/texture/textures/red_laser.png"));

    // make/connect a timer to move() the bullet every so often
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(53);
}

Bullet::Bullet(int x, int y)
{
    //setRect(0,0,10,50);
    setPixmap(QPixmap(":/texture/textures/Blue_laser.png"));
    setPos(x,y);

    // make/connect a timer to move() the bullet every so often
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveE()));

    // start the timer
    timer->start(60);
}


void Bullet::move()
{
    bool collision = false;
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            colliding_items[i]->setVisible(false);
            game->increasePoints();
            game->updateStats();

            delete this;
            // return (all code below refers to a non existint bullet)
            return;
        }
    }

    if( collision == false)
    {
        if(y() > 5)
            setPos(x(),y() - 10);
        else {
            scene()->removeItem(this);
            delete this;
        }
    }

}

void Bullet::moveE()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
            if (typeid(*(colliding_items[i])) == typeid(Player)){
                game->player->decreaseLife();
                game->updateStats();
                scene()->removeItem(this);
                delete this;
                return;
            }
        }


    if(y() < 670)
        setPos(x(),y() + 10);
    else {
        delete this;
    }

}
