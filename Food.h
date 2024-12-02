#ifndef FOOD_H
#define FOOD_H

#include "objPos.h"
#include "objPosArrayList.h"

class Food
{
    private: 
        objPos foodPos;
        objPosArrayList  * foodBucket; 

    public:

        Food();     //Constructor
        Food(Food const &f);     //Copy Constructor
        Food& operator=(Food const &f);     //Copy Assignment Operator
        ~Food();    //Destructor

        void generateFood(objPosArrayList* blockOff);

        objPos getFoodPos() const;
        objPos grabFoodItem(int index);

        int bucketSize();
        bool spotTaken(objPosArrayList* blockOff, int x, int y); 

};

#endif