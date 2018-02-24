/*
 * Board.h
 *
 *  Created on: Feb 24, 2018
 *      Author: omrish
 */

#include <iostream>

#ifndef BOARD_H_
#define BOARD_H_

enum Direction {UP,DOWN,LEFT,RIGHT};

class Board{
	int height;
	int width;
public:
	Board(int height,int width):height(height),width(width){};
	virtual ~Board(){};
	virtual void Move(Direction dir) = 0;
	virtual void Draw() = 0;
	//End Of game exception
	class GameOverException{};
};


#endif /* BOARD_H_ */
