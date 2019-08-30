#include "enemy.h"
#include <QtDebug>
#include "game.h"



Enemy::Enemy()
{
    srand( time( nullptr ) );

    index = 0;
    // set size and position
    //setRect(0,0,70,70);
    setPixmap(QPixmap(":/texture/textures/invadres.png"));
    setPos(20,15);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(shoot()));
    timer->start(3500 + x());

}

void Enemy::setIndex(unsigned int i)
{
   index =  i;
   if(index <= 11)
   {
       setPos(x() + index * 105, y());
   }
   else if (index > 11 && index <=23)
   {
       setPos(x() + (index-12) * 105, y()+100);
   }
   else if (index > 23 && index <=35)
   {
       setPos(x() + (index-24) * 105, y()+200);
   }



}

void Enemy::shoot()
{
    if(this->isVisible())
    {
        int randShoot =((std::rand() % 2222) + 666);
        timer->setInterval(3500 + randShoot);
        bullet = new Bullet(x(),y());
        bullet->setPos(x()+40,y());
        scene()->addItem(bullet);
    }

}
