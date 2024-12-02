#include "objPosArrayList.h"

using namespace std;

#include <iostream>
using namespace std;

//From lecture

objPosArrayList::objPosArrayList()//Constructor Method
{
    arrayCapacity = ARRAY_MAX_CAP;
    listSize = 0;
    aList = new objPos[ARRAY_MAX_CAP];  
    for(int i = 0; i < ARRAY_MAX_CAP - 1; i++)
    {
        aList[i] = objPos();
    }
}

objPosArrayList::objPosArrayList(int foodListSize)//Constructor Method
{
    arrayCapacity = ARRAY_MAX_CAP;
    listSize = foodListSize;
    aList = new objPos[ARRAY_MAX_CAP];  
    for(int i = 0; i < ARRAY_MAX_CAP - 1; i++)
    {
        aList[i] = objPos();
    }
}

objPosArrayList::~objPosArrayList()//Destructor Method
{
    delete[] aList;
}

objPosArrayList::objPosArrayList(objPosArrayList const &arr)//Copy constructor Method
{
    listSize = arr.listSize;
    arrayCapacity = arr.arrayCapacity;
    aList = new objPos[ARRAY_MAX_CAP];
    for(int i = 0; i < listSize - 1; i++)
    {
        aList[i] = arr.aList[i];
    }
}

objPosArrayList& objPosArrayList::operator =(objPosArrayList const &arr)//Copy Assignment Operator Method
{
    if(this != &arr)
    {
        listSize = arr.listSize;
        arrayCapacity = arr.arrayCapacity;
        for(int i = 0; i < listSize - 1; i++)
        {
            aList[i] = arr.aList[i];
        }
    }

    return *this;
}

int objPosArrayList::getSize() const //List Size Getter
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos) // Inserting Head Element
{
    if(listSize == arrayCapacity)
    {
        cout << "Array list is full" << endl;
    }

    for(int i = listSize; i > 0; i--)
    {
        aList[i] = aList[i-1];
    }

    aList[0] = thisPos;
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos) //Inserting Tail Element
{
    if(listSize == arrayCapacity)
    {
        cout << "Array list is full" << endl;
    }

    aList[listSize] = thisPos;
    listSize++;
}

void objPosArrayList::removeHead() //Removing Head
{
   if(listSize != arrayCapacity)
   {
        //Shifting elements 1 index left
        for(int i = 0; i < listSize - 1; i++)
        {
            aList[i] = aList[i + 1];
        }
        listSize--;
   }
   
   else
   {    
        cout << "No head to delete" << endl;
   }
}  

void objPosArrayList::removeTail() //Removing Tail Element
{
    if(listSize != 0)
    {
       listSize--;
    }

    else
    {    
        cout << "No tail to delete" << endl;
    }
}

objPos objPosArrayList::getHeadElement() const //Head element getter
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const //Tail Element Getter
{
    return aList[listSize - 1];
}

objPos objPosArrayList::getElement(int index) const //Snake Element Getter
{
    if(index >= 0 && index < listSize)
    {
        return aList[index];
    }

    else
    {
        cout << "Tried to get element of out of acccess index" << endl;
        return objPos();
    }
}

// Replace/Insert an element at a specific index
void objPosArrayList::insertElement(int index, objPos food) const 
{
    //Shift elements from index to end one right
    if(index >= 0 && index < listSize)
    {
        
       aList[index] = food ; 
    }

    else
    {
        cout << "Tried to get element of out of acccess index" << endl;
    }
}