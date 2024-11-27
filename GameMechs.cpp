#include "GameMechs.h"
#include "MacUILib.h"

#include <stdlib.h>
#include <time.h>

GameMechs::GameMechs()
{
    input = 0;
    exitFlag = 0;
    loseFlag = 0;
    score = 0;

    boardSizeX = 30;
    boardSizeY = 15;

}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = 0;
    loseFlag = 0;
    score = 0;

    boardSizeX = boardX;
    boardSizeY = boardY;
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    
}

bool GameMechs::getExitFlagStatus() const
{
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;
}
    

char GameMechs::getInput() const
{
    return input;
}

int GameMechs::getScore() const
{
    return score;
}

void GameMechs::incrementScore()
{
    score++;
}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    exitFlag = 1;
}

void GameMechs::setLoseFlag()
{
    loseFlag = 1;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

// More methods should be added here

Food::Food()
{   
    foodPos = objPos();
}

Food::~Food()
{
    
}

void Food::generateFood(objPos blockOff, GameMechs board)
{
    srand(time(NULL));
    int xPos, yPos;

    do
    {
        xPos = rand()%(board.getBoardSizeX()-2)+1;
        yPos = rand()%(board.getBoardSizeY()-2)+1;
    }
    while(xPos == blockOff.pos->x && yPos == blockOff.pos->y);
    
    //foodPos = objPos(xPos, yPos, '@');
    foodPos.pos->x = xPos;
    foodPos.pos->y = yPos;

}

objPos Food::getFoodPos() const
{
    foodPos.pos;
}

