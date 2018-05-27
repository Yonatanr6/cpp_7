/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Yoni
 *
 * Created on May 26, 2018, 3:05 PM
 */

#include "TicTacToe.h"
#include "DummyPlayers.h"
#include "Champion.h"

#include <iostream>
using namespace std;


void printResults(const TicTacToe& game) {
	cout << endl << "The final board is " << endl << game.board();
	cout << "And the winner is " << game.winner().name() 
	     << ", playing as " << game.winner().getRole() << "!" << endl;
}

void playAndPrintResults(TicTacToe& game, Player& xPlayer, Player& oPlayer) {
	game.play(xPlayer, oPlayer);
	printResults(game);
}

void playAndPrintWinner(TicTacToe& game, Player& xPlayer, Player& oPlayer) {
	game.play(xPlayer, oPlayer);
	cout << "The winner is " << game.winner().name() 
	     << ", playing as " << game.winner().getRole() << "!" << endl;
}


int main() {
	TicTacToe game(4);       // Initializes a game on a 4x4 board
	XYPlayer player1;
	YXPlayer player2;
	IllegalPlayer player3;
	ExceptionPlayer player4;

	playAndPrintResults(game, player1, player2);
	/*
		The final board is 
		XXXX
		O...
		O...
		O...
    	And the winner is XYPlayer, playing as X!
	*/

	playAndPrintResults(game, player2, player1);  
	/*
		The final board is 
		XOOO
		X...
		X...
		X...
        And the winner is YXPlayer, playing as X!
	*/

	playAndPrintResults(game, player1, player3);  
	/*
		The final board is 
		X...
		....
		....
		....
        And the winner is XYPlayer, playing as X!
	*/


	playAndPrintResults(game, player3, player1);  
	/*
		The final board is 
		XO..
		....
		....
		....
        And the winner is XYPlayer, playing as O!
	*/

	playAndPrintResults(game, player2, player4);  
	/*
		The final board is 
		X...
		....
		....
		....
		And the winner is YXPlayer, playing as X!
	*/

	playAndPrintResults(game, player4, player2);  
	/*
		The final board is 
		....
		....
		....
		....
		And the winner is YXPlayer, playing as O!
	*/


	Champion champion;
	playAndPrintWinner(game, champion, player1);
		// The winner is <your name>, playing as X!
	playAndPrintWinner(game, player1, champion);
		// The winner is <your name>, playing as O!
	playAndPrintWinner(game, champion, player2);
		// The winner is <your name>, playing as X!
	playAndPrintWinner(game, player2, champion);
		// The winner is <your name>, playing as O!
	playAndPrintWinner(game, champion, player3);
		// The winner is <your name>, playing as X!
	playAndPrintWinner(game, player3, champion);
		// The winner is <your name>, playing as O!
	playAndPrintWinner(game, champion, player4);
		// The winner is <your name>, playing as X!
	playAndPrintWinner(game, player4, champion);
		// The winner is <your name>, playing as O!

	return 0;
}