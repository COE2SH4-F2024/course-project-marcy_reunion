#include "objPosArrayList.h"

// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.
#include <iostream>
using namespace std;

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()      //Constructor
{
    arrayCapacity = ARRAY_MAX_CAP;
    listSize = 0;
    aList = new objPos[ARRAY_MAX_CAP];  
    for(int i = 0; i < ARRAY_MAX_CAP - 1; i++)
    {
        aList[i] = objPos();
    }
}

objPosArrayList::objPosArrayList(int foodListSize)      //Constructor
{
    arrayCapacity = ARRAY_MAX_CAP;
    listSize = foodListSize;
    aList = new objPos[ARRAY_MAX_CAP];  
    for(int i = 0; i < ARRAY_MAX_CAP - 1; i++)
    {
        aList[i] = objPos();
    }
}

objPosArrayList::~objPosArrayList()     //Destructor 
{
    delete[] aList;
}

objPosArrayList::objPosArrayList(objPosArrayList const &arr)        //Copy constructor
{
    listSize = arr.listSize;
    arrayCapacity = arr.arrayCapacity;
    aList = new objPos[ARRAY_MAX_CAP];
    for(int i = 0; i < listSize - 1; i++)
    {
        aList[i] = arr.aList[i];
    }
}

objPosArrayList& objPosArrayList::operator =(objPosArrayList const &arr)
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

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(listSize == arrayCapacity)
    {
        cout << "Array list is full" << endl;
        return;
    }

    for(int i = listSize; i > 0; i--)
    {
        aList[i] = aList[i-1];
    }

    aList[0] = thisPos;
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if(listSize >= arrayCapacity)
    {
        cout << "Congratulations You Win!" << endl;

        return;
    }

    aList[listSize] = thisPos;
    listSize++;
}

void objPosArrayList::removeHead()
{
   if(listSize != arrayCapacity)
   {
        for(int i = 0; i < listSize - 1; i++)
        {
            aList[i] = aList[i + 1];
        }
        listSize--;
   }
   
//    else
//    {    
//         cout << "No head to delete" << endl;
//    }
}  

void objPosArrayList::removeTail()
{
    if(listSize != 0)
    {
       listSize--;
    }

    // else
    // {    
    //     cout << "No tail to delete" << endl;
    // }
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize - 1];
}

objPos objPosArrayList::getElement(int index) const
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

//Function to replace/insert an element into a certain index
void objPosArrayList::insertElement(int index, objPos food) const
{
    if(index >= 0 && index < listSize)
    {
       aList[index] = food ; 
    }

    else
    {
        cout << "Tried to get element of out of acccess index" << endl;
    }
}

