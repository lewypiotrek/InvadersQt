#include "game.h"

Game::Game()
{
    // SETINGS --------------
    //set window size
       width = 1289;
       height = 720;
       score = 0;
       setBackgroundBrush(QBrush(QImage(":/texture/textures/background.png")));

    // set number of enemys
       EnemysNum = 36;


    // CREATING OBJECTS --------------

    // create the scene
       scene = new QGraphicsScene();
       scene->setSceneRect(0,0,width,height);
    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
       setScene(scene);
       setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
       setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
       setFixedSize(width,height);

    // create player
       player = new Player();
    // make the player focusable and set it to be the current focus
       player->setFlag(QGraphicsItem::ItemIsFocusable);
       player->setFocus();
       scene->addItem(player);


    // create enemys and pointer array
       enemy = new Enemy[EnemysNum];
       pEnemy = new Enemy* [EnemysNum];
    // set pointers to the enemys and add enemys to the scene
       for(unsigned int i = 0; i < EnemysNum;i++)
       {
           pEnemy[i] = &enemy[i];
           enemy[i].setIndex(i);
           scene->addItem(pEnemy[i]);
       }

    // create lifeboard
       lifeboard = new QGraphicsTextItem;
       lifeboard->setPlainText(QString("LIFE: ") + QString::number((player->getLife())));
       lifeboard->setDefaultTextColor(Qt::red);
       lifeboard->setFont(QFont("times",16));
       lifeboard->setPos(0,680);
       scene->addItem(lifeboard);
    // create scoreboard
       scoreboard = new QGraphicsTextItem;
       scoreboard->setPlainText(QString("SCORE: ") + QString::number(score));
       scoreboard->setDefaultTextColor(Qt::blue);
       scoreboard->setFont(QFont("times",16));
       scoreboard->setPos(1150,680);
       scene->addItem(scoreboard);

}

Game::~Game()
{
    delete scoreboard;
    delete lifeboard;
    delete player;
    delete scene;
    for(unsigned int i = 0; i > EnemysNum;i++)
    {
        delete [] pEnemy[i];
    }
    delete enemy;

}

int Game::xSize()
{
    return width;
}

int Game::ySize()
{
    return height;
}

void Game::updateStats()
{
    lifeboard->setPlainText(QString("LIFE: ") + QString::number((player->getLife())));
    scoreboard->setPlainText(QString("SCORE: ") + QString::number(score));
}

void Game::increasePoints()
{
    score++;
    int respawn = score%4;
    if(respawn == 0)
    {
        for(unsigned int i = 0; i < EnemysNum; i++)
        {
            short random =((std::rand() % 4) + 2);
            if (random == 3)
            {
                enemy[i].show();
                enemy[i].setActive(true);
            }

        }
    }
}

int Game::getPoints()
{
    return score;
}
