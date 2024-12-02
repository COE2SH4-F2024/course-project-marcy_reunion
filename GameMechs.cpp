#include "GameMechs.h"

GameMechs::GameMechs()
{ // constructor of gamemechs
 score =0;
 exitFlag = false; 
 loseFlag= false;
 winFlag = false;
}

GameMechs::GameMechs(int boardX, int boardY)
{ // constructor, the board sizes are specified
    boardSizeX = boardX; 
    boardSizeY = boardY; 
    score =0;
    exitFlag = false; 
    loseFlag = false;
    winFlag = false;
}

// do you need a destructor?
// a destructor is not needed as there is allocation on heap, so nothing needs to be deleted
GameMechs::~GameMechs()
{
    
}

bool GameMechs::getExitFlagStatus() const
{// return exit flag value
    return exitFlag;
}

bool GameMechs::getLoseFlagStatus() const
{ // return lose flag value
    return loseFlag; 
}

bool GameMechs::getWinFlagStatus() const
{// return win flag value
    return winFlag; 
}
    

char GameMechs::getInput() const
{ // return the current input
    return input; 
}

int GameMechs::getScore() const
{ // return current value of score
    return score; 
}

int GameMechs::incrementScore(int increment)
{ // increment the score by value specified in parameter
    score += increment;
    return score;
}

int GameMechs::getBoardSizeX() const
{
    //Starting from 0
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{// return value of y axis board
    return boardSizeY; 
}


void GameMechs::setExitFlag()
{ // set the game exit flag to true
    exitFlag = true; 

}

void GameMechs::setLoseFlag()
{ // set the game lose flag to true
    loseFlag = true; 
}

void GameMechs::setWinFlag()
{ // set the game win flag to true
    winFlag = true; 
}

void GameMechs::setInput(char this_input)
{ //  updates current input based on specification from parameter
    input = this_input;
}

void GameMechs::clearInput()
{ // clears the user input
    input = 0; 
}

void GameMechs::setScore(int val)
{ // sets the score to value specified in parameter
    score=val; 
}