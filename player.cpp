#include "player.h"
#include "game.h"
#include <QGraphicsRectItem>
#include <QtDebug>


extern Game * game;

Player::Player()
{
    //this->setRect(0,0,50,50);
    setPixmap(QPixmap(":/texture/textures/ship.png"));
    setPos(600,600);
    life = 3;
    shootMode = 0;
}

void Player::keyPressEvent(QKeyEvent * event)
{
    if(event->key() == Qt::Key_Left)
    { 
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right)
    {
        setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Space)
    {
        if(shootMode == 1)
        {
            bullet = new Bullet();
            bullet->setPos(x(),y());
            scene()->addItem(bullet);

            bullet = new Bullet();
            bullet->setPos(x()+28,y());
            scene()->addItem(bullet);
        }
        else
        {
            bullet = new Bullet();
            bullet->setPos(x()+25,y());
            scene()->addItem(bullet);
        }
    }
}

void Player::increaseLife()
{
    life++;
}

void Player::decreaseLife()
{
    life--;

    //check life if life < 1 player lose
    if (life < 1)
    {
        msg = new QMessageBox;
        msg->setText(" YOU LOSE x( \n SCORE: " + QString::number(game->getPoints()) + " ");
        msg->setWindowTitle("GAME OVER");
        msg->setIcon(QMessageBox::Critical);
        int respond = msg->exec();
        if(respond == QMessageBox::Ok)
        {
            exit(EXIT_FAILURE);
        }

    }
}

int Player::getLife()
{
    return life;
}
