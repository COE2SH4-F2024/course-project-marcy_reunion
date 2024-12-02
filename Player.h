#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Food.h"

class GameMechs;        //removing this stops the code from compiling **IMPORTANT
class Food;             //removing this stops the code from compiling **IMPORTANT

class Player
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  //direction state

        Player(GameMechs* thisGMRef);
        ~Player();

        Dir getFSMState();
        objPosArrayList* getPlayerPos() const; 
        void updatePlayerDir();
        int movePlayer(Food *snakeFood);
         
        int checkFoodConsumption(Food* snakeFood);
        void increasePlayerLength(int num); 
        bool checkSelfCollision();
        bool victoryCheck();

    private:
        objPosArrayList* playerPosList;  
        Dir myDir;

        GameMechs* gameMechRef; //reference to game mechanics
};

#endif