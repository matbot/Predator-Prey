/*********************************************
 * *Author: Mathew McDade
 * *Date: Sat Oct 29 14:04:56 PDT 2016
 * *Description: Ant class implementation.
 * *********************************************/

#include "ant.hpp"
#include "utils.hpp"

/*******************
 * Ant Constructor
 * ****************/
Ant::Ant(Game* b, int r, int c):Critter(b,r,c)
{
	//passes to virtual base class' constructor without requiring any additional initializations.
}

Ant::~Ant()
{
	//nothing
}

/***********
 * getCrit
 * ********/
Species Ant::getCritter()
{
	return ANT;
}

/************
 * antBreed
 * *********/
void Ant::breed()
{
	if(aliveFor==3 && hasEmptyNeighbor()) //ant won't breed if no open neighbors.
		while(aliveFor==3)
		{
			Direction d = static_cast<Direction>(randInt(1,4));//I love casting my randInt util.
			if(isOpenNeighbor(d))
			{
				newCritter(d);
				aliveFor = 0;
			}
		}
}
			
/***********
 * antMove
 * ********/
void Ant::move()
{
	if(hasEmptyNeighbor())
		while(hasMoved==false)
		{
			Direction d = static_cast<Direction>(randInt(1,4));
			if(isOpenNeighbor(d))
			{
				moveThisCritter(d);
				aliveFor++;
				hasMoved = true;
			}
		}
}


