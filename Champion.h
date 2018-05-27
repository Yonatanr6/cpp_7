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

class Champion : public Player
{
public:
    const Coordinate play(const Board& board) override ;
    const string name() const override{
 return "Yonatan Rofsov & Shiran Anasker";
 }
};

