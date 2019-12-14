/*********************************************
 * *Author: Mathew McDade
 * *Date: Sat Oct 29 14:10:02 PDT 2016
 * *Description: Doodle class header.
 * *********************************************/

#ifndef MMCD_DOODLE_HPP
#define MMCD_DOODLE_HPP

#include "critter.hpp"

class Doodle: public Critter
{
private:
	int hunger; //Doodle has the extra hunger variable to indicate when the bug should starve.
public:
	Doodle(Game*,int,int);
	~Doodle();
	void breed();
	void move();
	void starve();
	Species getCritter();
	bool hasAntNeighbor();
	bool isAntNeighbor(Direction);
};

#endif
