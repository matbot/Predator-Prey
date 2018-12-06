/*********************************************
 * *Author: Mathew McDade
 * *Date: Sat Oct 29 13:51:17 PDT 2016
 * *Description: Game class implementation.
 * *********************************************/

#include "game.hpp"
#include "critter.hpp"
#include "ant.hpp"
#include "doodle.hpp"
#include "wall.hpp"
#include "utils.hpp"
#include <iostream>
#include <unistd.h>

using std::cin;
using std::cout;
using std::endl;


/*****************
 * Constructors
 * *************/
Game::Game(int turns)
{
	rows = 20;
	columns = 20;
	currentTurn = 0;
	totalTurns = turns;

	board = new Critter**[rows+2]; //both contructors create Wall around rest of array.
	for(int i=0;i<rows+2;i++)
		board[i] = new Critter*[columns+2];
	for(int i=1;i<=rows;i++)
		for(int j=1;j<=columns;j++)
			board[i][j] = NULL;
	for(int i=0;i<rows+2;i++)
	{
		board[i][0] = new Wall(this,i,0);
		board[i][columns+1] = new Wall(this,i,columns+1);
	}
	for(int j=1;j<=columns;j++)
	{
		board[0][j] = new Wall(this,0,j);
		board[rows+1][j] = new Wall(this,rows+1,j);
	}

	for(int i=0;i<100;i++)
	{
		bool placed = false;
		while(placed==false)
		{
			int r = randInt(1,20);
			int c = randInt(1,20);
			if(whatCritter(r,c)==EMPTY)
			{
				board[r][c] = new Ant(this,r,c);
				placed = true;
			}
		}
	}
	for(int i=0;i<5;i++)
	{
		bool placed = false;
		while(placed==false)
		{
			int r = randInt(1,20);
			int c = randInt(1,20);
			if(whatCritter(r,c)==EMPTY)
			{
				board[r][c] = new Doodle(this,r,c);
				placed = true;
			}
		}
	}
}

Game::Game(int turns, int rows, int cols, int ants, int dbugs)
{
	totalTurns = turns;
	currentTurn = 0;
	this->rows = rows;
	this->columns = cols;

	board = new Critter**[rows+2];
	for(int i=0;i<rows+2;i++)
		board[i] = new Critter*[columns+2];
	for(int i=1;i<=rows;i++)
		for(int j=1;j<=columns;j++)
			board[i][j] = NULL;
	for(int i=0;i<rows+2;i++)
	{
		board[i][0] = new Wall(this,i,0);
		board[i][columns+1] = new Wall(this,i,columns+1);
	}
	for(int j=1;j<=columns;j++)
	{
		board[0][j] = new Wall(this,0,j);
		board[rows+1][j] = new Wall(this,rows+1,j);
	}
	for(int i=0;i<ants;i++)
	{
		bool placed = false;
		while(placed==false)
		{
			int r = randInt(1,rows);
			int c = randInt(1,columns);
			if(whatCritter(r,c)==EMPTY)
			{
				board[r][c] = new Ant(this,r,c);
				placed = true;
			}
		}
	}
	for(int i=0;i<dbugs;i++)
	{
		bool placed = false;
		while(placed==false)
		{
			int r = randInt(1,rows);
			int c = randInt(1,columns);
			if(whatCritter(r,c)==EMPTY)
			{
				board[r][c] = new Doodle(this,r,c);
				placed = true;
			}
		}
	}
}

/***************************
 * Destructor: deleeeeeete
 * ************************/
Game::~Game()
{
	for(int i=0;i<rows+2;i++)
		for(int j=0;j<columns+2;j++)
			delete board[i][j];
	for(int i=0;i<rows+2;i++)
		delete[] board[i];
	delete[] board;
	board = NULL;
}


/***************************************************
 * isCritter? //checks if a cell is null to prevent 
 * undefined behavior of calling the virtual 
 * functions on a null pointer; also check if cell 
 * contains Wall to keep simulation within borders.
 * *************************************************/
bool Game::isCritter(int r, int c)
{
	if(board[r][c]==NULL)
		return false;
	else if(board[r][c]->getCritter()==WALL)
		return false;
	else if(board[r][c]->getCritter()==ANT || board[r][c]->getCritter()==DOODLE)
		return true;
	else
		return false; //added to make sure no functions are called on non critter objects.
}

/****************
 * whatCritter?
 * *************/
Species Game::whatCritter(int r, int c)
{
	if(board[r][c]==NULL)
		return EMPTY;
	else
		return board[r][c]->getCritter();
}

/********************
 * hasEmptyNeighbor?
 * *****************/
bool Game::hasEmptyNeighbor(int r, int c)
{
	if(board[r-1][c]==NULL || board[r+1][c]==NULL)
		return true;
	else if(board[r][c-1]==NULL || board[r][c+1]==NULL)
		return true;
	else
		return false;
}

/******************
 * hasAntNeighbor?
 * ***************/
bool Game::hasAntNeighbor(int r, int c)
{
	if(whatCritter(r-1,c)==ANT || whatCritter(r+1,c)==ANT)
		return true;
	else if(whatCritter(r,c-1)==ANT || whatCritter(r,c+1)==ANT)
		return true;
	else
		return false;
}

/**************
 * setCritter:
 * ***********/
void Game::setCritter(Species s, int r, int c)
{
	if(s==EMPTY)
	{
		delete board[r][c];
		board[r][c] = NULL;
	}
	else if(s==ANT)
		board[r][c]= new Ant(this,r,c);

	else if(s==DOODLE)
	{
		delete board[r][c];
		board[r][c]= new Doodle(this,r,c);
	}
}

/******************
 * moveThisCritter
 * ****************/
void Game::moveThisCritter(int r, int c, Direction d)
{
	if(d==UP)
	{
		if(isCritter(r-1,c))
			delete board[r-1][c];
		board[r-1][c] = board[r][c];
		board[r][c] = NULL;
	}
	else if(d==DOWN)
	{
		if(isCritter(r+1,c))
			delete board[r+1][c];
		board[r+1][c] = board[r][c];
		board[r][c] = NULL;
	}
	else if(d==LEFT)
	{
		if(isCritter(r,c-1))
			delete board[r][c-1];
		board[r][c-1] = board[r][c];
		board[r][c] = NULL;
	}
	else if(d==RIGHT)
	{
		if(isCritter(r,c+1))
			delete board[r][c+1];
		board[r][c+1] = board[r][c];
		board[r][c] = NULL;
	}
}
	
/*************
 * printBoard
 * **********/
void Game::printBoard()
{
	for(int i=0;i<rows+2;i++)
	{
		for(int j=0;j<columns+2;j++)
		{
			switch(whatCritter(i,j)){
				case WALL: cout << "\u2B1B";
						 break;
				case EMPTY: cout << "\u0020";
						  break;
				case ANT: cout << "\u204E";
						break;
				case DOODLE: cout << "\u24E7";}
			cout << " ";
		}
		cout << endl;
	}
	cout << "Current Turn: " << currentTurn << " of " << totalTurns << endl << endl;
}

/******************************************************************
 * runBoard: doodlebugs move, breed, and starve before ants move.
 * I found this pattern to produce the most competitive structure
 * for the simulation.
 * ****************************************************************/
void Game::runBoard()
{
	while(currentTurn < totalTurns)
	{
		for(int i=1;i<=rows;i++)
			for(int j=1;j<=columns;j++)
			{
				if(whatCritter(i,j)==DOODLE)
					board[i][j]->move();
			}
		for(int i=1;i<=rows;i++)
			for(int j=1;j<=columns;j++)
			{
				if(whatCritter(i,j)==DOODLE)
				{
					board[i][j]->breed();
					board[i][j]->starve();
				}
			}
		for(int i=1;i<rows+1;i++)
			for(int j=1;j<columns+1;j++)
			{
				if(whatCritter(i,j)==ANT)
					board[i][j]->move();
			}
		for(int i=1;i<=rows;i++)
			for(int j=1;j<=columns;j++)
			{
				if(isCritter(i,j))
					board[i][j]->breed();
			}
		currentTurn++;
		clearPage();
		printBoard();
		usleep(75000);

		for(int i=1;i<=rows;i++)
			for(int j=1;j<=columns;j++)
				if(isCritter(i,j))
					board[i][j]->setHasMoved(false);
	}
}
