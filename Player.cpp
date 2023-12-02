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
    playerPosList->removeTail();
    
}

