#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 200
#include <iostream>
#include "objPos.h"

class objPosArrayList{
    private:
        objPos* aList;
        int sizeList;  //num of elements
        int sizeArray;  //max size
 
    public:
        objPosArrayList();
        ~objPosArrayList();
        objPosArrayList(const objPosArrayList &l);//deep copy

    //getter
        int getSize();

        void getHeadElement(objPos &returnPos);
        void getTailElement(objPos &returnPos);
        void getElement(objPos &returnPos, int index);
        
    //setter   
        void insertHead(objPos thisPos);
        void insertTail(objPos thisPos);

        void removeHead();
        void removeTail();
};

#endif