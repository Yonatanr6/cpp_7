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



void TicTacToe::play(Player &xPlayer, Player &oPlayer)
{
    game ='.'; 
    int game_size = size*size;
    int count = 0;
    xPlayer.setRole('X');
    oPlayer.setRole('O');
    Coordinate c(0,0);
    while(count < game_size){
        count++;
        try{
            c.setCoordinate(xPlayer.play(game));
            if(game[c]=='.')
                game[c] = xPlayer.getChar();
            else{
                champion = &oPlayer;
                //return;
            }
        }
        catch(const string& msg) {
            champion = &oPlayer; 
            //return;
        }

        if(checkWinner('X')) {
            champion = &xPlayer; 
            return;
        }
        count++;
        if(count < game_size){
            try{
                c.setCoordinate(oPlayer.play(game));
                if(game[c]=='.')
                    game[c] = oPlayer.getChar();
                else{
                    champion = &xPlayer; 
                    return;
                }
            }
            catch(const string& msg) {
                champion = &xPlayer; 
                return;
            }

            if(checkWinner('O')) {
                champion= &oPlayer; 
                return;
            }
        }
    }
    champion = &oPlayer;
}
bool TicTacToe::checkWinner(char c)
{
    bool winning = true;

    for(int i = 0; i< size ; i++)
    {
        winning = true;
        for(int j = 0; j<size ; j++)
        {
            if(game[{i,j}] != c){
                winning = false;
                break;
            }
        }
        if(winning)
            return true;

        winning = true;
        for(int k = 0; k<size ; k++)
        {
            if(game[{k,i}] != c){
                winning = false;
                break;
            }
        }
        if(winning)
            return true;
    }

    winning = true;
    for(int i = 0; i<size ; i++)
    {
        if(game[{i,i}] != c){
            winning = false;
            break;
        }
    }
    if(winning)
        return true;
    winning = true;
    for(int i = 0; i<size ; i++)
    {
        if(game[{size-i-1,i}] != c){
            winning = false;
            break;
        }
    }
    return winning;
}