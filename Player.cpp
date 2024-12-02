#include "Player.h"
#include "iostream"


Player::Player(GameMechs* thisGMRef)
{
    playerPosList = new objPosArrayList(); 
    mainGameMechsRef = thisGMRef;
    myDir = STOP;
    playerPosList->insertHead(objPos(11,5,'*'));
    
}

Player::Dir Player::getFSMState(){ // return the current dir of snake
    return myDir; 
}

Player::~Player() // delete player position array list located on the heap
{
    delete playerPosList; 
}

objPosArrayList* Player::getPlayerPos() const // return player position array list
{
    return playerPosList; 
}

void Player::updatePlayerDir() // change the direction of the snake according to the input from user
{
       char input = mainGameMechsRef->getInput();
       // checking the input entered, and making sure the constraint is met, and then changing dir according
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
    objPos updateHeadPos = playerPosList->getHeadElement(); 

    switch (myDir) { // change player position based on curr direction 
    case DOWN:
        updateHeadPos.pos->y++;
        if (updateHeadPos.pos->y == mainGameMechsRef->getBoardSizeY()- 1 ){ // wrap around logic for top
            updateHeadPos.pos->y = 1;
        }
        break;

    case UP:
        updateHeadPos.pos->y--;
        if (updateHeadPos.pos->y == 0) { // wrap around logic for bottom
            updateHeadPos.pos->y = mainGameMechsRef->getBoardSizeY()-2;
        }
        break;

    case RIGHT:
        updateHeadPos.pos->x++;
        if (updateHeadPos.pos->x == mainGameMechsRef->getBoardSizeX()-1) {// wrap around logic for right side
            updateHeadPos.pos->x = 1; 
        }
        break;

    case LEFT:
        updateHeadPos.pos->x--;
        if (updateHeadPos.pos->x== 0) { // wrap around logic for left side
            updateHeadPos.pos->x = mainGameMechsRef->getBoardSizeX()-2;
        }
        break;
    case STOP:
        break; 
    }

    if (checkSelfCollision()){ // check to see if the snake has collided with itself
        mainGameMechsRef->setLoseFlag();
        return 1; 
    }
    // SPECIAL FOOD LOGIC 
    if(checkFoodConsumption(snakeFood) == 2) // if snake eats "S" food increase length by 3
    {
        increasePlayerLength(3);
        snakeFood->generateFood(playerPosList);
        mainGameMechsRef->setScore(mainGameMechsRef->incrementScore(1));
    }
    if(checkFoodConsumption(snakeFood) == 1) // if snake eats "s" food increase length by 3
    {
        increasePlayerLength(1);
        snakeFood->generateFood(playerPosList);
        mainGameMechsRef->setScore(mainGameMechsRef->incrementScore(3));
    }
    if((checkFoodConsumption(snakeFood) == -1)) // if snake eats "@" food increase length by 3
    {
       increasePlayerLength(1);
       snakeFood->generateFood(playerPosList);
       mainGameMechsRef->setScore(mainGameMechsRef->incrementScore(1));
    }

    // allows snake to keep its size
    playerPosList->insertHead(updateHeadPos); 
    playerPosList->removeTail();
    return 0;

   
}

int Player::checkFoodConsumption(Food *snakeFood){ // checker of snake eating food
    for (int i =0; i<snakeFood->bucketSize(); i++){
        objPos currentFood = snakeFood->grabFoodItem(i);
        // if the location of the snake matches the location of food, value is returned for type of food
        if (playerPosList->getHeadElement().pos->x == currentFood.pos->x  && playerPosList->getHeadElement().pos->y == currentFood.pos->y){
            // checks the type of food eaten, and returns a specific value, used later for the snake to grow
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
    { // checking if the snake head is at the same location of a snake body part
        objPos currentBodyPart = playerPosList->getElement(i);
        if (playerHead.pos->x == currentBodyPart.pos->x && playerHead.pos->y==currentBodyPart.pos->y)
        {
            return true; 
        }
    }
    return false; 
}

void Player::increasePlayerLength(int num){ // increases the length of the player at the tail
    objPos newTail = playerPosList->getTailElement();
        for(int i = 0; i < num; i++)
        {
            playerPosList->insertTail(objPos(newTail.pos->x,newTail.pos->y,'*')); 
        }
}

void Player::victoryCheck() // checking if the lenght of the snake is the size of the array
{
    if(playerPosList->getSize() >= ARRAY_MAX_CAP)
    {
        mainGameMechsRef->setWinFlag(); // set win condition
    }
}