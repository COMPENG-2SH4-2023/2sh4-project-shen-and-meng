#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    playerPosList = new objPosArrayList();
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(15,7,'*');
    playerPosList->insertHead(playerPos);
}

Player::~Player(){
    delete playerPosList;
}


objPosArrayList* Player::getPlayerList()
{
    // return the reference to the playerPos arrray list
    
    return playerPosList;
}








void Player::updatePlayerDir()
{
    // PPA3 input processing logic     
    if (myDir == STOP)
    {
        if (mainGameMechsRef->getInput() == mainGameMechsRef->getKeyLeft())
        {
            myDir = LEFT;
        }
        else if (mainGameMechsRef->getInput() == mainGameMechsRef->getKeyRight())
        {
            myDir = RIGHT;
        }
        else if (mainGameMechsRef->getInput() == mainGameMechsRef->getKeyUp())
        {
            myDir = UP;
        }
        else if (mainGameMechsRef->getInput() == mainGameMechsRef->getKeyDown())
        {
            myDir = DOWN;
        }
    }
    if (myDir == UP)
    {
        if (mainGameMechsRef->getInput() == mainGameMechsRef->getKeyLeft())
        {
            myDir = LEFT;
        }
        else if (mainGameMechsRef->getInput() == mainGameMechsRef->getKeyRight())
        {
            myDir = RIGHT;
        }
    }
    else if (myDir == DOWN)
    {
        if (mainGameMechsRef->getInput() == mainGameMechsRef->getKeyLeft())
        {
            myDir = LEFT;
        }
        else if (mainGameMechsRef->getInput() == mainGameMechsRef->getKeyRight())
        {
            myDir = RIGHT;
        }
    }
    else if (myDir == LEFT)
    {
        if (mainGameMechsRef->getInput() == mainGameMechsRef->getKeyUp())
        {
            myDir = UP;
        }
        else if (mainGameMechsRef->getInput() == mainGameMechsRef->getKeyDown())
        {
            myDir = DOWN;
        }
    }
    else if (myDir == RIGHT)
    {
        if (mainGameMechsRef->getInput() == mainGameMechsRef->getKeyUp())
        {
            myDir = UP;
        }
        else if (mainGameMechsRef->getInput() == mainGameMechsRef->getKeyDown())
        {
            myDir = DOWN;
        }
    }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    if (myDir == UP)
    {
        playerPos.y -= 1;
    }
    else if (myDir == DOWN)
    {
        playerPos.y += 1;
    }
    else if (myDir == LEFT)
    {
        playerPos.x -= 1;
    }
    else if (myDir == RIGHT)
    {
        playerPos.x += 1;
    }
    if (playerPos.x == mainGameMechsRef->getBoardSizeX()-1)
    {
        playerPos.x = 1;
    }
    else if (playerPos.x == 0)
    {
        playerPos.x = mainGameMechsRef->getBoardSizeX()-2;
    }
    else if (playerPos.y == mainGameMechsRef->getBoardSizeY()-1)
    {
        playerPos.y = 1;
    }
    else if (playerPos.y == 0)
    {
        playerPos.y = mainGameMechsRef->getBoardSizeY()-2;
    }
    playerPosList->insertHead(playerPos);
    if (!checkFoodConsumption())
    {
        playerPosList->removeTail();
    }
    playerPosList->getHeadElement(playerPos);
}


bool Player::checkFoodConsumption()
{
    objPosArrayList* Foodlist;
    objPos foodpos;
    objPos head;
    playerPosList->getHeadElement(head);
    Foodlist = mainGameMechsRef->getfoodlist();
    for (int i = 0; i < Foodlist->getSize();i++){

        Foodlist->getElement(foodpos,i);

        if ((head.x == foodpos.x)&&(head.y == foodpos.y)){
            if(foodpos.symbol>='3'&&foodpos.symbol<='9'){
                mainGameMechsRef->setDuration((int(foodpos.symbol)-47)*3);//duration =3*simbol steps
                mainGameMechsRef->setEffect(1);//score*5 in each consumption
                mainGameMechsRef->setBonus(3);

            }
            if(foodpos.symbol>='0'&&foodpos.symbol<'3'){
                if(playerPosList->getSize()>(int(foodpos.symbol)-47)){
                    playerPosList->sizeIncrement(-(int(foodpos.symbol)-47));
                }
                else{
                    playerPosList->sizeIncrement(-(playerPosList->getSize()-1));
                }
                mainGameMechsRef->setEffect(2);
                mainGameMechsRef->setDuration(3);
            }
            return true;
        }
    }

    return false;
        
    
}

bool Player::checkSelfCollision()
{
    int i;
    objPos head;
    objPos body;
    playerPosList->getHeadElement(head);
    for (i = 1;i<playerPosList->getSize();i++)
    {
        playerPosList->getElement(body,i);
        if(body.x == head.x && body.y == head.y)
        {
            return true;
        }

    }
    return false;

    
}

void Player::increasePlayerLength()
{
    playerPosList->sizeIncrement(1);
}
