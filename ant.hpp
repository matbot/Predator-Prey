/***************************************************
 * *Author: Mathew McDade
 * *Date: Sat Oct 29 14:03:41 PDT 2016
 * *Description: Critter derived Ant class header.
 * Nothing too crazy here.
 * ***********************************************/

#ifndef MMCD_ANT_HPP
#define MMCD_ANT_HPP

#include "critter.hpp"

class Ant: public Critter
{
private:

public:
	Ant(Game*,int,int);
	~Ant();
	void breed();
	void move();
	Species getCritter();
};

#endif
