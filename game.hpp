/*************************************************
 * *Author: Mathew McDade
 * *Date: Sat Oct 29 13:46:27 PDT 2016
 * *Description: Game class header. 
 * *********************************************/
#ifndef MMCD_GAME_HPP
#define MMCD_GAME_HPP

enum Species { ANT, DOODLE, EMPTY, WALL };
enum Direction { UP = 1, DOWN, LEFT, RIGHT };

class Critter; //forward declaration of abstract class.

class Game
{
private:
	int currentTurn;
	int totalTurns;
	int rows;
	int columns;
	Critter*** board; //board is a pointer to a pointer to a pointer to a Critter...
public:
	Game(int); //default simulation.
	Game(int,int,int,int,int); //custom user simulation.
	~Game(); //must free all this crazy memory.

	bool isCritter(int,int);
	Species whatCritter(int,int);
	bool hasEmptyNeighbor(int,int);
	bool hasAntNeighbor(int,int);
	void setCritter(Species,int,int);
	void moveThisCritter(int,int,Direction);

	void printBoard();
	void runBoard();
};

#endif

