#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"
#include "Player.h"
#include "Food.h"

using namespace std;

class Player;       //removing this stops the code from compiling **IMPORTANT
class Food;         //removing this stops the code from compiling **IMPORTANT

class GameMechs
{
    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        bool winFlag;
        int score;

        int boardSizeX;
        int boardSizeY;

        objPos food;

    public:
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs(); // is this one needed at all? Why or why not?
        
        bool getExitFlagStatus() const; 
        void setExitFlag();
        bool getLoseFlagStatus() const;
        void setLoseFlag();
        bool getWinFlagStatus() const;
        void setWinFlag();

        char getInput() const;
        void setInput(char this_input);
        void clearInput();
        char getPrevInput(); 
    

        int getBoardSizeX() const;
        int getBoardSizeY() const;
        
        int getScore() const;
        int incrementScore(int);
        void setScore(int val); 
        
        // More methods should be added here
};

#endif