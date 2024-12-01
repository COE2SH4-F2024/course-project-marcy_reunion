#include "Food.h"
#include <iostream>
#include <time.h>
using namespace std;

Food::Food()     //Constructor
{
   foodBucket = new objPosArrayList(5); 
}

Food::~Food()    //Destructor
{  
    delete foodBucket;
    delete foodPos.pos;
}

Food::Food(Food const &f)     //Copy Constructor
{   
    foodPos.pos = new Pos;
    foodPos.pos->x = f.foodPos.pos->x;
    foodPos.pos->y = f.foodPos.pos->y;
    foodPos.symbol = f.foodPos.symbol;
}

Food& Food::operator=(Food const &f)     //Copy Assignment Operator
{
    if(this != &f)
    {
        foodPos.pos = new Pos;
        foodPos.pos->x = f.foodPos.pos->x;
        foodPos.pos->y = f.foodPos.pos->y;
        foodPos.symbol = f.foodPos.symbol;
    }
    
    return *this;
}

void Food::generateFood(objPosArrayList* blockOff)
{
    int i, RandNum_x, RandNum_y;
    srand(time(NULL));

    for(i=0; i<5; i++)
    {
        RandNum_x = (rand()%18)+1;
        RandNum_y = (rand()%8)+1;

        foodPos.pos->x = RandNum_x;
        foodPos.pos->y = RandNum_y;

        if(i==0) foodPos.symbol = 'S';
        else if(i==1) foodPos.symbol = 's';
        else foodPos.symbol = '@';

        if(snakeBodyCheck(blockOff, RandNum_x, RandNum_y))
        {
            i--;
            continue;
        }
        if(foodInBucket())
        {
            i--;
            continue;
        }

        foodBucket->insertElement(i, foodPos);
    }

    return; 
}

objPos Food::getFoodPos() const
{
    return foodPos;
}

objPos Food::grabFoodItem(int index){
    return foodBucket->getElement(index); 
}

int Food::bucketSize(){

    return foodBucket->getSize(); 
}

bool Food::foodInBucket(){

    int i=0;
    for (i = 0; i<foodBucket->getSize(); i++)
    {
        objPos currentFood = foodBucket->getElement(i).getObjPos();
        if (foodPos.pos->x == currentFood.pos->x && foodPos.pos->y == currentFood.pos->y)
        {
            return true; 
        }
    }
    return false;
}

bool Food::snakeBodyCheck(objPosArrayList* blockOff, int x, int y)
{
    for (int i =0; i<blockOff->getSize(); i++ )
    {
         if(blockOff->getElement(i).pos->x == x && blockOff->getElement(i).pos->y == y)
         {
            return true; 
         }
    }
    return false;
}

