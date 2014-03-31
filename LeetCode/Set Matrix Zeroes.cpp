/*
 * =====================================================================================
 *
 *       Filename:  Set Matrix Zeroes.cpp
 *
 *    Description:  LeetCode
 *
 *        Version:  1.0
 *        Created:  03/31/2014 01:54:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LiuYi (), swliuyi@gamil.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        bool firstline = 0;
        bool firstcol = 0;

        for( int i = 0 ; i < matrix[0].size() ; i++ )
        {
            if( matrix[0][i] == 0 )
            {
                firstline = 1;
            }
        }

        for( int i = 0 ; i < matrix.size() ; i++ )
        {
            if( matrix[i][0] == 0 )
            {
                firstcol = 1;
            }
        }
        
        
        for( int i = 1 ; i < matrix.size() ; i++ )
        {
            for( int j = 1 ; j < matrix[0].size() ; j++ )
            {
                if( matrix[i][j] == 0 )
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
       for( int i = 1 ; i < matrix[0].size() ; i++ )
       {
           if( matrix[0][i] == 0 )
           {
               for( int j = 1 ; j < matrix.size() ; j++ )
               {
                   matrix[j][i] = 0;
               }
           }
       }

       for( int i = 1 ; i < matrix.size() ; i++ )
       {
           if( matrix[i][0] == 0 )
           {
               for( int j = 1 ; j < matrix[0].size() ; j++ )
               {
                   matrix[i][j] = 0;
               }
               
           }
       }
       
       if( firstline == 1 )
       {
           for( int i = 0 ; i < matrix[0].size() ; i++ )
           {
               matrix[0][i] = 0;
           }
       }

       if(firstcol == 1)
       {
           for( int i = 0 ; i < matrix.size() ; i++ )
           {
               matrix[i][0] = 0;
           }
           
       }

    }
};
