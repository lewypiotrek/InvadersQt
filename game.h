#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.h"
#include "enemy.h"
#include <QGraphicsTextItem>
#include <cstdlib>




class Game: public QGraphicsView
{
public:
    Game();
    ~Game();
    QGraphicsScene * scene;
    Player * player;
    Enemy * enemy;
    Enemy ** pEnemy;
    QGraphicsTextItem * lifeboard;
    QGraphicsTextItem * scoreboard;
    int xSize();
    int ySize();
    void updateStats();
    void increasePoints();
    int getPoints();

private:
      int score;
      int width;
      int height;
      unsigned int EnemysNum;
};

#endif // GAME_H
