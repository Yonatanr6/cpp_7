/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Champion.h
 * Author: Yoni
 *
 * Created on May 26, 2018, 3:06 PM
 */

#include "DummyPlayers.h"
#pragma once
#include <iostream>
using namespace std;

class Champion : public Player{
    
public:

    const Coordinate play(const Board& board) override{
//        int k = board.size-1;
//        for (int i=0; i<board.size; ++i) {
//        Coordinate c{k-i,i};
//        if(i==1 && board[{0,k}] == '.'){
//            c.setRow(0); 
//            c.setCol(board.size-1);
//        }
//        if(board[c]=='.') {
//            return c;
//        }
//    }
    for (int i = 0; i < board.size; i++) {
        for (int j = 0; j < board.size; j++) {
          Coordinate c{i,j};
          if(board[c] != '.')
            return c;
        }
      }
    return {0,0};
    };
    
    
    const string name() const override{
 return "Yonatan Rofsov & Shiran Anasker";
 }
};

