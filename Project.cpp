#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "gameMechs.h"

#include "Player.h"
#include "Food.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs *ptr_gameMechs;
Food *ptr_food;
bool exitFlag = false;

string gameBoard[10]={
    {"$$$$$$$$$$$$$$$$$$$$"},  
    {"$                  $"},   
    {"$                  $"},
    {"$                  $"},
    {"$                  $"},
    {"$                  $"},
    {"$                  $"},
    {"$                  $"},
    {"$                  $"},
    {"$$$$$$$$$$$$$$$$$$$$"}    
};

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    ptr_gameMechs = new GameMechs();
    ptr_food = new Food();
}

void GetInput(void)
{
   if(MacUILib_hasChar()) //Checking whether there is an input character
    {
        char input = MacUILib_getChar();
        ptr_gameMechs->setInput(input);
    }
}

void RunLogic(void)
{
    char input = ptr_gameMechs->getInput();
    ptr_gameMechs->clearInput();


}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    for (int i =0; i<10;i++){
        for (int j=0; j<20; j++){
            MacUILib_printf("%c", gameBoard[i][j]);
        }
        MacUILib_printf("\n");
    }

    

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();

    delete ptr_gameMechs;
    delete ptr_food;


}
