#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "gameMechs.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs *ptr_gameMechs;
bool exitFlag = 0;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag = false)  
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

    GameMechs Game1 = GameMechs();
    ptr_gameMechs = &Game1;
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
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();
}
