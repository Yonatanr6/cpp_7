/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: Yoni
 *
 * Created on May 27, 2018, 3:57 PM
 */
#pragma once
#include "Board.h"
#include <iostream>
using namespace std;

class Player{

public:
    char role;
    Player(){}
    Player(char c){
        if (c=='O' || c== 'X')
            role=c;
        else{
            IllegalCharException ex(c);
            throw ex;
        }
    }
    void setChar(char c) {role = c;}
    char getChar(){return role;}
    virtual const string name() const =0;
    virtual const Coordinate play(const Board& board)=0 ;
};

