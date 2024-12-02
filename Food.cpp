#include "Food.h"
#include <iostream>
#include <time.h>
using namespace std;

Food::Food() //Constructor Method
{
   foodBucket = new objPosArrayList(5); 
}

Food::~Food()//Destructor Method
{  
    delete foodBucket;
    delete foodPos.pos;
}

Food::Food(Food const &f)//Copy Constructor Method
{   
    foodPos.pos = new Pos;
    foodPos.pos->x = f.foodPos.pos->x;
    foodPos.pos->y = f.foodPos.pos->y;
    foodPos.symbol = f.foodPos.symbol;
}

Food& Food::operator=(Food const &f)//Copy Assignment Operator Method
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

void Food::generateFood(objPosArrayList* blockOff, int x, int y) //Food Generation Algorithm
{
    int i, RandNum_x, RandNum_y, foods = 5;
    srand(time(NULL));

    //If the snake is taking up more than 195 squares, there won't be 5 places to generate food--adjusting accordingly
    if(blockOff->getSize()> 195){ 
        foods = 200 - blockOff->getSize(); 
    }

    //Typically, foods=5, generate 5 food
    for(i=0; i<foods; i++)
    {
        //Assigning random position to the foodPos object
        RandNum_x = (rand()%(x-2))+1;
        RandNum_y = (rand()%(y-2))+1;

        foodPos.pos->x = RandNum_x;
        foodPos.pos->y = RandNum_y;

        //Assigning a symbol to the foodPos object (ensuring 2 will be the special symbols)
        if(i==0) foodPos.symbol = 'S';
        else if(i==1) foodPos.symbol = 's';
        else foodPos.symbol = '@';

        //if food is generated in snakebody, restart the loop with the same i value
        if(spotTaken(blockOff, RandNum_x, RandNum_y))
        {
            i--;
            continue;
        }
    
        //insert the generated food data into the bucket
        foodBucket->insertElement(i, foodPos);
    }

    return; 
}

objPos Food::getFoodPos() const //Food position getter
{
    return foodPos;
}

objPos Food::grabFoodItem(int index) //Food bucket item getter
{
    return foodBucket->getElement(index); 
}

int Food::bucketSize() //Food bucket size getter
{

    return foodBucket->getSize(); 
}

//Function to check whether the food is being generated in already taken spot (snake or other food)
bool Food::spotTaken(objPosArrayList* blockOff, int x, int y) 
{   

    int i;

    //Checking if food is generated in snake body
    for (i = 0; i<blockOff->getSize(); i++)
    {
        if(blockOff->getElement(i).pos->x == x && blockOff->getElement(i).pos->y == y)
        {
            return true; 
        }

    }

    //Checking if food is generated in another food spot
    for (i = 0; i<foodBucket->getSize(); i++)
    {
        //Creating a temporary object for the food in bucket we're looking at
        objPos currentFood = foodBucket->getElement(i).getObjPos();
        if (foodPos.pos->x == currentFood.pos->x && foodPos.pos->y == currentFood.pos->y)
        {
            return true; 
        }
    }

    return false;
}

