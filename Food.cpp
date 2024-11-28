#include "GameMechs.h"
#include "Food.h"

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
