#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Food.h"
#include <time.h>
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

void Initialize(void);
void GetInput(void);
int RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);


//Global pointers to the objects needed for the game
GameMechs* mechInst = nullptr;
Player* snakeHead = nullptr; 
Food* snakeFood = nullptr;

int main(void)
{
    Initialize();
    //Code runs until a flag is set
    while((mechInst->getExitFlagStatus() == false) && (mechInst->getLoseFlagStatus() == false) && (mechInst->getWinFlagStatus() == false)){
        GetInput();
        if (RunLogic() != 1);
        {
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
    
    //Initializing the object classes
    mechInst = new GameMechs(20,10);
    snakeHead = new Player(mechInst);
    snakeFood = new Food();
    snakeFood->generateFood(snakeHead->getPlayerPos());

}

void GetInput(void)
{
    //Getting and setting inputs
    if (MacUILib_hasChar()){
        mechInst->setInput(MacUILib_getChar());
    }
}

int RunLogic(void)
{
    //Esc key is hit--exit code
    if (mechInst->getInput()== 27){
        mechInst->setExitFlag();
    }
    //update the direction of the snake
    snakeHead->updatePlayerDir();
    if (snakeHead->movePlayer(snakeFood)==1){//If an exit flag is hit--skip the draw screen process
        return 1; 
    }
    mechInst->clearInput(); //clear the input so no input is double-processed

    return 0;
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    //Gameboard structure to print
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

    objPosArrayList* theCharac = snakeHead->getPlayerPos(); //Setting a pointer to the position of the snake head

    for (int i = 0; i<mechInst->getBoardSizeY(); i++){//Iterating through each row
        for (int j = 0; j<mechInst->getBoardSizeX(); j++){//Iterating through each column
            int printed = 0; //Variable to track if the coordinate has been printed 

            for (int k = 0; k<theCharac->getSize(); k++){ //iterating through the snake body
                objPos snake = theCharac->getElement(k);
                if (snake.pos->x== j && snake.pos->y == i){//if said location contains the snake body--print the snake
                    MacUILib_printf("%c", snake.getSymbol());
                    printed = 1;
                    break;
                }
            }
            
            if (printed == 0){
                //Iterating through the food bucket to see if said location holds food
                for (int foodLoc = 0; foodLoc < snakeFood->bucketSize(); foodLoc++){
                    objPos foodProp = snakeFood->grabFoodItem(foodLoc);

                    if(foodProp.pos->x == j && foodProp.pos->y == i){   
                        MacUILib_printf("%c", foodProp.getSymbol());
                        printed = 1; 
                        break; 
                    }
                }
            }
            //if it doesn't contain food or a snake body--print the gameboard
            if (printed == 0){
                MacUILib_printf("%c", gameBoard[i][j]);
            } 
        }
        MacUILib_printf("\n");
    }
    //Printing the score and special character legend
    MacUILib_printf("Special Characters:\nEating S = +3 score\nEating s = +3 snake length\n");
    MacUILib_printf("\nScore: %d", mechInst->getScore());   
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}

void CleanUp(void)
{
    MacUILib_clearScreen();    
    
    //Different game ending messages depending on the situation
    if(mechInst->getLoseFlagStatus() == true)
        MacUILib_printf ("Sorry, you lost.. Try again!"); 
    else if(mechInst->getWinFlagStatus() == true)
        MacUILib_printf("Congratulations, you win!!");
    else
        MacUILib_printf("Come back again!");
    MacUILib_printf("\nFinal Score: %d", mechInst->getScore());
    //Clearing the heap
    delete snakeFood;
    delete mechInst;
    delete snakeHead;
}
 