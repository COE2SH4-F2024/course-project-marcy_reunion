#include "objPosArrayList.h"

// Paste your Tested implementation here.

objPosArrayList::objPosArrayList()
{
    aList = new objPos[ARRAY_MAX_CAP];
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;

}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{ 
    if(listSize >= ARRAY_MAX_CAP) return;

    for(int i = listSize; i>0; i--)
    {
        aList[i] = aList[i-1]; //takes the last element and replaces it with the element before
    }
    aList[0] = thisPos;
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize >= arrayCapacity) return;

    aList[listSize] = thisPos;
    listSize++;
}

void objPosArrayList::removeHead()
{
    if (listSize==0) return;

    for(int i = 0; i<listSize - 1; i++)
    {
        aList[i] = aList[i+1];
    }
    listSize--;
}

void objPosArrayList::removeTail()
{
    if(listSize>0)
    {
        listSize--;
    }
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize-1];
}

objPos objPosArrayList::getElement(int index) const
{
    if(index<0) index = 0;
    else if(index>=listSize) index = listSize - 1;
    
    return aList[index];
}
// Paste your Tested implementation here.
// Paste your Tested implementation here.
