#include "objPosArrayList.h"

using namespace std;

objPosArrayList::objPosArrayList(){
    sizeList=0;
    sizeArray=ARRAY_MAX_CAP;
    aList = new objPos[ARRAY_MAX_CAP];
}

objPosArrayList::~objPosArrayList(){
    delete[] aList;
}
objPosArrayList::objPosArrayList(const objPosArrayList &l){
    sizeList=l.sizeList;
    sizeArray=l.sizeArray;
    aList = new objPos[ARRAY_MAX_CAP];
    for(int i=0;i<sizeList;i++){
        aList[i]=l.aList[i];
    }
}
int objPosArrayList::getSize(){
    return sizeList;
}

void objPosArrayList::insertHead(objPos thisPos){
    if(sizeList==sizeArray){cout<<"array full"<<endl;return;}
    sizeList += 1;
    for(int i=sizeList;i>0;i--){
        aList[i].setObjPos(aList[i-1]);
    }
    aList[0]=thisPos;
    //sizeList += 1;
}

void objPosArrayList::insertTail(objPos thisPos){
    if(sizeList==sizeArray){cout<<"array full"<<endl;return;}
    aList[sizeList++].setObjPos(thisPos);
    
}

void objPosArrayList::removeHead(){
    if(sizeArray==0){cout<<"array empty"<<endl;return;}
    for(int i=1;i<sizeList;i++){
        aList[i-1].setObjPos(aList[i]);
    }
    sizeList--;
}

void objPosArrayList::removeTail(){
    if(sizeArray==0){cout<<"array empty"<<endl;return;}
    sizeList--;
}

void objPosArrayList::getHeadElement(objPos &returnPos){
    returnPos.setObjPos(aList[0]);

}

void objPosArrayList::getTailElement(objPos &returnPos){
    returnPos.setObjPos(aList[sizeList-1]);
}

void objPosArrayList::getElement(objPos &returnPos, int index){
    returnPos.setObjPos(aList[index]);
}

void objPosArrayList::sizeIncrement(int d)
{
    sizeList += d;
}
