/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TicTacToe.cpp
 * Author: Yoni
 * 
 * Created on May 26, 2018, 3:06 PM
 */

#include "TicTacToe.h"
#include <iostream>
using namespace std;


void TicTacToe::play(Player &xPlayer, Player &oPlayer){
    game ='.'; 
    int turns = game.size*game.size;
    int count = 0;
    xPlayer.setRole('X');
    oPlayer.setRole('O');
    Coordinate c(0,0);
    while(count < turns){
        count++;
        try{c.setCoordinate(xPlayer.play(game));
            if(game[c]=='.')
                game[c] = xPlayer.getChar();
            else{
                player = &oPlayer;
                return;
            }
        }
        catch(...) {
            player = &oPlayer; 
            return;
        }
        if(checkWinner('X')&&count) {
            player = &xPlayer; 
            return;
        }
        count++;
        if(count < turns){
            try{c.setCoordinate(oPlayer.play(game));
                if(game[c]=='.')
                    game[c] = oPlayer.getChar();
                else{
                    player = &xPlayer; 
                    return;
                }
            }
            catch(...) {
                player = &xPlayer; 
                return;
            }
            if(checkWinner('O')&&count) {
                player= &oPlayer; 
                return;
            }
        }
    }
    player = &oPlayer;
}


bool TicTacToe::checkWinner(char c){
    bool winning = true;
    int k=game.size-1;

    for(int i = 0; i< game.size ; i++){
        
        winning = true;
        for(int j = 0; j<game.size ; j++){
            if(game[{i,j}] != c && game[{j,i}] != c){
                winning = false;
                break;
            }
        }
        if(winning)
            return true;
       
         if(game[{i,i}] != c){
            winning = false;
            break;
        }
          if(winning)
            return true;
    }
    winning = true;
    for(int i = 0; i<game.size ; i++){
        if(game[{k-i,i}] != c){
            winning = false;
            break;
        }
    }
    return winning;
}