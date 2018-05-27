/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TicTacToe.h
 * Author: Yoni
 *
 * Created on May 26, 2018, 3:06 PM
 */
#pragma once
#include "DummyPlayers.h"
#include <iostream>
using namespace std;

class TicTacToe{
public:
    Board game;
    int size;
    Player* champion;

public:
    TicTacToe(int n);
    Board board() const;
    Player& winner() const;
    void play(Player& xPlayer, Player& oPlayer);
    bool checkWinner(char c);

};
