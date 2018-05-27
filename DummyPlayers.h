/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DummyPlayers.h
 * Author: Yoni
 *
 * Created on May 26, 2018, 3:06 PM
 */
#pragma once
#include "Board.h"
#include "Player.h"
#include <iostream>
using namespace std;




class XYPlayer: public Player{
public:
    const string name() const override { return "XYPlayer"; }
    const Coordinate play(const Board& board) override;
};


/*
	This player scans the board looping on y then on x,
	and plays on the first empty cell.
*/
class YXPlayer: public Player {
public:
    const string name() const override { return "YXPlayer"; }
    const Coordinate play(const Board& board) override;
};


/*
   This player makes illegal moves -
   it tries to override cells of the other player.
   It should always lose.
*/
class IllegalPlayer: public Player {
public:
    const string name() const override { return "YXPlayer"; }
    const Coordinate play(const Board& board) override;
};


/*
	This player always throws an exception.
	It should always lose.
*/
class ExceptionPlayer: public Player {
public:
    const string name() const override { return "YXPlayer"; }
    const Coordinate play(const Board& board) override;
};

