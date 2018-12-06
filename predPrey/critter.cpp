

#include <iostream>
#include "critter.hpp"

/***************
 * Constructor
 * ************/
Critter::Critter()
{
}

Critter::Critter(Game* g, int r, int c)
{
	rCoord = r;
	cCoord = c;
	bord = g;
	aliveFor = 0;
	hasMoved = false;
}

/************************
 * virtual Destructor
 * ********************/
Critter::~Critter()
{
	//do nothing
}

/*******************
 * newCritter
 * **********/
void Critter::newCritter(Direction d)
{
	if(d==UP)
		bord->setCritter(getCritter(),rCoord-1,cCoord);
	else if(d==DOWN)
		bord->setCritter(getCritter(),rCoord+1,cCoord);
	else if(d==LEFT)
		bord->setCritter(getCritter(),rCoord,cCoord-1);
	else if(d==RIGHT)
		bord->setCritter(getCritter(),rCoord,cCoord+1);
}

/******************
 * hasEmptyNeighbor
 * ****************/
bool Critter::hasEmptyNeighbor()
{
	return bord->hasEmptyNeighbor(rCoord,cCoord);
}

/******************
 * isOpenNeighbor
 * ***************/
bool Critter::isOpenNeighbor(Direction d)
{
	switch(d) {
		case UP: if(bord->whatCritter(rCoord-1,cCoord)==EMPTY)
				    return true;
			    break;
		case DOWN: if(bord->whatCritter(rCoord+1,cCoord)==EMPTY)
					 return true;
				 break;
		case LEFT: if(bord->whatCritter(rCoord,cCoord-1)==EMPTY)
					 return true;
				 break;
		case RIGHT: if(bord->whatCritter(rCoord,cCoord+1)==EMPTY)
					  return true;
	}
	return false;
}

/*******************
 * moveThisCritter
 * ****************/
void Critter::moveThisCritter(Direction d)
{
	bord->moveThisCritter(rCoord,cCoord,d);
	if(d==UP)
		rCoord-=1;
	else if(d==DOWN)
		rCoord+=1;
	else if(d==LEFT)
		cCoord-=1;
	else if(d==RIGHT)
		cCoord+=1;
}

void Critter::setHasMoved(bool b)
{
	hasMoved = b;
}
