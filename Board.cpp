/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Board.h"
#include <iostream>
#include <vector>
#include <list>
#pragma once
using namespace std;

ostream& operator<<(ostream& out,const Board& board){
    out<<"";
 for(int i=0;i<board.size;i++){
        for(int j=0;j<board.size;j++){
           out << board.board[i][j].get_node(); 
        }
        out << "" <<endl;
    }
    return out;

}

Node& Board::operator[](const list<int> list){
    int a=list.front(),b=list.back();
    if(a<0 || a>=size || b<0 || b>=size){
        IllegalCoordinateException ex(a,b);
        throw ex;
    }
    return this->board[a][b];
}

Node& Board::operator[](const Coordinate& c) const{
    int a = c.getRow(), b = c.getCol();

    if (a < size && b < size)
        return board[a][b];
    else
    {
        IllegalCoordinateException ex(a,b);
        throw ex;
    }
}

Node& Node::operator=(char c)
{
   if(c=='X' || c=='O' || c=='.'){
        this->cell = c;
        return *this;
   }
    else{
       IllegalCharException ex(c);
        throw ex;
    }
 
}

//char Node::operator=(const Node node){
//    return node.cell;
//}

Node::operator char()const{
    return cell;
}

Board& Board::operator=(char c){
    if (c=='.') {
        for (int j = 0; j < size; ++j) {
            for (int i = 0; i < size; ++i) {
                board[i][j] = '.';
            }
        }
    }
    else{
       IllegalCharException ex(c);
        throw ex; 
    }
    return *this;
}

Board& Board::operator=(const Board &b){
    if (this==&b)
        return *this;
    if (b.size!=size) {
        for (int i = 0; i < size; i++)
            delete[] board[i];
        delete [] board;

        size = b.size;
        board = new Node*[b.size];
        for (int i = 0; i < size; i++) 
            board[i] = new Node [size];
    }
    for (int i=0; i < size; ++i){
        for(int j=0 ;j < size ; j++){
            board[i][j]= Node{b.board[i][j].get_node()};
        }
    }
    return *this;
}

//bool Node::operator==(char c) const{
//    return cell ==c;
//}
//bool Node::operator==(const Node& node) const{
//    return cell == node.cell;
//}
//bool Node::operator!=(char c) const{
//    return cell !=c;
//}
//bool Node::operator!=(const Node& node) const{
//    return cell !=node.cell;
//}
//
// bool Board::operator==(const Board& board) const{
//     if (size != board.size)
//        return false;
//    for (int i = 0; i < size; ++i) {
//        for (int j = 0; j < size; ++j) {
//            if (this->board[i][j] != board.board[i][j].get_node())
//                return false;
//        }
//    }
//    return true;
// }

