/***********************************************
 * *Author: Mathew McDade
 * *Date: Sat Oct 29 13:58:31 PDT 2016
 * *Description: Critter virtual class header.
 * *********************************************/

#ifndef MMCD_CRITTER_HPP
#define MMCD_CRITTER_HPP

#include "game.hpp" //Critter was forward declared in game class.

class Critter
{
private:
protected:
	int rCoord;
	int cCoord;
	int aliveFor;
	bool hasMoved;
	Game* bord; //that's right; a pointer to the ***
public:
	Critter();
	Critter(Game*,int,int);
	virtual ~Critter();
	virtual void breed() {};
	virtual void starve() {};
	virtual void move() {};
	virtual Species getCritter() = 0;
	void newCritter(Direction);
	bool hasEmptyNeighbor();
	bool isOpenNeighbor(Direction);
	void moveThisCritter(Direction);
	void setHasMoved(bool);
};
#endif
