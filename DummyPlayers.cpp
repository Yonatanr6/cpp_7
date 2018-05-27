/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DummyPlayers.cpp
 * Author: Yoni
 * 
 * Created on May 26, 2018, 3:06 PM
 */

#include <iostream>
using namespace std;

#include "DummyPlayers.h"


const Coordinate XYPlayer::play(const Board& board) {
    for (int x=0; x<board.size; ++x) {
        for (int y=0; y<board.size; ++y) {
            Coordinate c{x,y};
            if (board[c]=='.') {
                return c;
            }
        }
    }
    return {0,0};  // did not find an empty square - play on the top-left
}


const Coordinate YXPlayer::play(const Board& board) {
    for (int y=0; y<board.size; ++y) {
        for (int x=0; x<board.size; ++x) {
            Coordinate c{x,y};
            if (board[c]=='.') {
                return c;
            }
        }
    }
    return {0,0};  // did not find an empty square - play on the top-left
}



/**
 * The illegal player tries to put a char on a cell owned by the other player.
 */
const Coordinate IllegalPlayer::play(const Board& board) {
    char charOfOtherPlayer = (
            role=='X'? 'O': 'X'
    );
    for (int y=0; y<board.size; ++y) {
        for (int x=0; x<board.size; ++x) {
            Coordinate c{x,y};
            if (board[c]==charOfOtherPlayer) {
                return c;
            }
        }
    }
    return {0,0};  // did not find an illegal square - play on the top-left
}


const Coordinate ExceptionPlayer::play(const Board& board) {
    throw string("hahaha");
}

