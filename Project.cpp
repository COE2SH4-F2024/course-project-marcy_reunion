#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Food.h"
#include <time.h>
#include "Player.h"


using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

void Initialize(void);
void GetInput(void);
int RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

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
GameMechs* mechInst = new GameMechs(20,10);
Player* snakeHead = new Player(mechInst); 

Food* snakeFood = nullptr;

int main(void)
{
    Initialize();
    while((mechInst->getExitFlagStatus() == false) && (mechInst->getLoseFlagStatus() == false) && (mechInst->getWinFlagStatus() == false)){
        GetInput();
        if (RunLogic() != 1);{
        DrawScreen();
        }
        LoopDelay();
    }
    CleanUp();
}

void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    snakeFood = new Food();
    snakeFood->generateFood(snakeHead->getPlayerPos());

    exitFlag = false;
}

void GetInput(void)
{
    if (MacUILib_hasChar()){
        mechInst->setInput(MacUILib_getChar());
    }
}

int RunLogic(void)
{
    if (mechInst->getInput()== 27){
        mechInst->setExitFlag();
    }
    snakeHead->updatePlayerDir();
    if (1==snakeHead->movePlayer(snakeFood)){
        return 1; 
    }
    mechInst->clearInput(); 
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    objPosArrayList* theCharac = snakeHead->getPlayerPos();

for (int i =0; i<mechInst->getBoardSizeY();i++){
        for (int j=0; j<mechInst->getBoardSizeX(); j++){
            int printed =0; 

            for (int  k = 0; k<theCharac->getSize(); k++){
            objPos snake = theCharac->getElement(k);
            if (snake.pos->x== j && snake.pos->y == i){
                MacUILib_printf("%c", snake.getSymbol());
                printed = 1; 
            }
            }
             if (printed!=1){
                for (int foodLoc =0; foodLoc < snakeFood->bucketSize(); foodLoc++){
                    objPos foodProp = snakeFood->grabFoodItem(foodLoc);

                    if(foodProp.pos->x == j && foodProp.pos->y == i)
                    {   printed =1; 
                        MacUILib_printf("%c", foodProp.getSymbol());
                        break; 
                    }
                }
            }
            if (printed!=1){
                MacUILib_printf("%c", gameBoard[i][j]);
                 
            } 
    }
    MacUILib_printf("\n");
  }
MacUILib_printf("\nEating S = +3 score\nEating s = +3 snake length\n");
MacUILib_printf("Score: %d", mechInst->getScore());   
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp(void)
{
    MacUILib_clearScreen();    
    
    if(mechInst->getLoseFlagStatus() == true)
        MacUILib_printf ("Unluckly, you lost.. Try again!"); 
    else if(mechInst->getWinFlagStatus() == true)
        MacUILib_printf("Congratulations, you win!!");
    else
        MacUILib_printf("Come back again!");
    delete snakeFood;
    delete mechInst;
    delete snakeHead;
}
 