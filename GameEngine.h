/*
 * GameEngine.h
 *
 *  Created on: Feb 24, 2018
 *      Author: omrish
 */

#ifndef GAMEENGINE_H_
#define GAMEENGINE_H_

//
// Created by Admin on 21/02/2018.
//

#ifndef SNAKE_GAMEENGINE_H
#define SNAKE_GAMEENGINE_H

#include <conio.h>
#include <afxres.h>
#include "Board.h"

class GameEngine{
private:
    bool quit = false;
    Board* board;
    char lastValidCharInput = 'w'; //initial value for this is 'w';
public:
    GameEngine(Board* board);
    void Input();
    void processKey(char key);
    void Run();
    char waitForUserInput(int second);
    bool checkValidKey(char c);
};

GameEngine::GameEngine(Board* board){
	if(!board){
		quit = true;
		std::cout<< "Probably a Memory allocation problem, the Game board pointed to NULL" << std::endl;
	}
	this->board = board;
}

void GameEngine::Input() {
    char current = waitForUserInput(1);
    try{
        processKey(current);
    }catch(Board::GameOverException&) {
        quit = true;
    }
}

void GameEngine::processKey(char key) {
    switch(key){
        case 'w':
            board->Move(UP);
            break;
        case 's':
            board->Move(DOWN);
            break;
        case 'd':
            board->Move(RIGHT);
            break;
        case 'a':
            board->Move(LEFT);
            break;
    }
}

void GameEngine::Run(){
    while(!quit){
        Input();
        board->Draw();
    }
}

char GameEngine::waitForUserInput(int quarterSeconds) {
    char c = this->lastValidCharInput;
    while(quarterSeconds != 0){
        if(_kbhit()){
            c = _getch();
            if(checkValidKey(c)){
            	this->lastValidCharInput = c;
            }
            break;
        }
        Sleep(100);
        --quarterSeconds;
    }
    return c;
}

bool GameEngine::checkValidKey(char c){
	if(c != 'a' && c != 's' && c!='d' && c!='w'){
		return false;
	}
	return true;
}


#endif //SNAKE_GAMEENGINE_H




#endif /* GAMEENGINE_H_ */
