/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Champion.cpp
 * Author: Yoni
 * 
 * Created on May 26, 2018, 3:06 PM
 */

#include "Champion.h"
#include <iostream>
using namespace std;


const Coordinate Champion::play(const Board& board) {
    for (int i=0; i<board.size; ++i) {
        int t = board.size-1-i;
        Coordinate c{t,i};
        t = board.size-1;
        if(i==1 && board[{0,t}] == '.'){
            c.setRow(0); c.setCol(board.size-1);
        }
        if(board[c]=='.') {
            return c;
        }
    }
    return {0,0};
}

