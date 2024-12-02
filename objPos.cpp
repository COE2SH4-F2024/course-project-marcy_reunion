#include "objPos.h"

objPos::objPos() 
{ // constructor, the Pos struct is assigned on to the heap, as the pos variable is a pointer
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

objPos::objPos(int xPos, int yPos, char sym)
{ // constructor, this one uses the values passed as parameters
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// Respect the rule of six / minimum four
// [TODO] Implement the missing special member functions to meet the minimum four rule

//Destructor
objPos::~objPos(){

    delete pos; 
}

//Copy Constructor
objPos::objPos(const objPos &a){
    pos = new Pos;
    pos->x = a.pos->x;
    pos->y = a.pos->y;
    symbol = a.symbol;


}

//Copy Assignmnet Constructor
objPos& objPos::operator=(const objPos &a){

   if(this != &a)
   {

        delete pos;
        this->pos = new Pos;
        this->pos->x  = a.pos->x;
        this->pos->y  = a.pos->y;
        this->symbol = a.symbol;
   }

    

    return *this;
}

void objPos::setObjPos(objPos o)
{ // copies the x, y and symbol from another objPos
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

void objPos::setObjPos(int xPos, int yPos, char sym)
{ // assign the x, y and symbol of a objPos
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

objPos objPos::getObjPos() const
{ // returns the x and y position, and symbol
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

char objPos::getSymbol() const
{ // return the symbol
    return symbol;
}

bool objPos::isPosEqual(const objPos* refPos) const
{ // compares the position of current and one passed in parameter, check if the same
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{ // if the position of the current and one passed in parameter is same, the symbol is return
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}