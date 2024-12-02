#include "Player.h"
#include "iostream"


Player::Player(GameMechs* thisGMRef)
{
    playerPosList = new objPosArrayList(); 
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPosList->insertHead(objPos(11,5,'*'));
    
}

Player::Dir Player::getFSMState(){
    return myDir; 
}

Player::~Player()
{
    delete playerPosList; 
}

objPosArrayList* Player::getPlayerPos() const
{
    return playerPosList; 
}

void Player::updatePlayerDir()
{
       char input = mainGameMechsRef->getInput();
        if ((input == 'w' || input == 'W') && myDir != DOWN) {
            myDir = UP;
        }
        else if ((input == 's' || input == 'S') && myDir != UP) {
            myDir = DOWN;
        }
        else if ((input == 'a' || input == 'A') && myDir != RIGHT) {
            myDir = LEFT;
        }
        else if ((input == 'd' || input == 'D') && myDir != LEFT) {
            myDir = RIGHT;
        }
}

int Player::movePlayer(Food *snakeFood)
{
    objPos nextHead = playerPosList->getHeadElement(); 

    switch (myDir) {
    case DOWN:
        nextHead.pos->y++;
        if (nextHead.pos->y == mainGameMechsRef->getBoardSizeY()- 1 ){
            nextHead.pos->y = 1;
        }
        break;

    case UP:
        nextHead.pos->y--;
        if (nextHead.pos->y == 0) {
            nextHead.pos->y = mainGameMechsRef->getBoardSizeY()-2;
        }
        break;

    case RIGHT:
        nextHead.pos->x++;
        if (nextHead.pos->x == mainGameMechsRef->getBoardSizeX()-1) {
            nextHead.pos->x = 1;
        }
        break;

    case LEFT:
        nextHead.pos->x--;
        if (nextHead.pos->x== 0) {
            nextHead.pos->x = mainGameMechsRef->getBoardSizeX()-2;
        }
        break;
    case STOP:
        break; 
    }

    if (checkSelfCollision()){
        mainGameMechsRef->setLoseFlag();
        return 1; 
    }
    
    if(checkFoodConsumption(snakeFood) == 1)
    {
        increasePlayerLength(1);
        snakeFood->generateFood(playerPosList);
        mainGameMechsRef->setScore(mainGameMechsRef->incrementScore(3));
    }

    if(checkFoodConsumption(snakeFood) == 2)
    {
        increasePlayerLength(3);
        snakeFood->generateFood(playerPosList);
        mainGameMechsRef->setScore(mainGameMechsRef->incrementScore(1));
    }

    if((checkFoodConsumption(snakeFood) == -1))
    {
       increasePlayerLength(1);
       snakeFood->generateFood(playerPosList);
       mainGameMechsRef->setScore(mainGameMechsRef->incrementScore(1));
    }

    playerPosList->insertHead(nextHead); 
    playerPosList->removeTail();
    return 0;

   
}

int Player::checkFoodConsumption(Food *snakeFood){
    for (int i =0; i<snakeFood->bucketSize(); i++){
        objPos currentFood = snakeFood->grabFoodItem(i);
        if (playerPosList->getHeadElement().pos->x == currentFood.pos->x  && playerPosList->getHeadElement().pos->y == currentFood.pos->y){
            if (currentFood.symbol == 'S'){
                return 1; 
            }
            else if(currentFood.symbol == 's'){
                return 2;
            }
            else{
                return -1; 
            }
        }
    }
    return 0;
}

bool Player::checkSelfCollision(){
    objPos playerHead = playerPosList->getHeadElement();
    for (int i =1; i<playerPosList->getSize(); i++)
    {
        objPos currentBodyPart = playerPosList->getElement(i);
        if (playerHead.pos->x == currentBodyPart.pos->x && playerHead.pos->y==currentBodyPart.pos->y)
        {
            return true; 
        }
    }
    return false; 
}

void Player::increasePlayerLength(int num){
    objPos newTail = playerPosList->getTailElement();
        for(int i = 0; i < num; i++)
        {
            playerPosList->insertTail(objPos(newTail.pos->x,newTail.pos->y,'*')); 
        }
}

void Player::victoryCheck()
{
    if(playerPosList->getSize() >= ARRAY_MAX_CAP)
    {
        mainGameMechsRef->setWinFlag();
    }
}