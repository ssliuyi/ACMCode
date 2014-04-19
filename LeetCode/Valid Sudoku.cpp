/*
 * =====================================================================================
 *
 *       Filename:  Valid Sudoku.cpp
 *
 *    Description:  leetcode
 *
 *        Version:  1.0
 *        Created:  04/19/2014 04:08:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LiuYi (), swliuyi@gamil.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
    public:
        bool isValidSudoku(vector<vector<char> > &board) {

            for( int i = 0 ; i < board.size() ; i++ )
            {

                set <char> temp1;
                set <char> temp2;
                //row
                for( int col = 0 ; col < board[0].size() ; col++ )
                {
                    if( board[i][col] != '.' )
                    {
                        if( temp1.find(board[i][col]) == temp1.end() )
                        {
                            temp1.insert(board[i][col]);
                        }
                        else    
                        {
                            return false;
                        }
                    }
                }

                //col
                for( int row = 0 ; row < board.size() ; row++ )
                {
                    if( board[row][i] != '.' )
                    {
                        if(temp2.find(board[row][i]) == temp2.end())
                        {
                            temp2.insert(board[row][i]);
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }
            for( int i = 0 ; i < board.size() ; i = i+3 )
            {
                for( int j = 0 ; j < board[0].size(); j = j+3 )
                {
                    set <char> temp;
                    for( int row = 0 ; row < 3 ; row++ )
                    {
                        for( int col = 0 ; col < 3 ; col++ )
                        {
                            if( board[i+row][j+col] != '.' )
                            {
                                if( temp.find(board[i+row][j+col]) == temp.end())
                                {
                                    temp.insert(board[i+row][j+col]);
                                }
                                else
                                {
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
            return true;
        }
};
