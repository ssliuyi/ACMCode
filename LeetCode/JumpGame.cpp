/*
 * =====================================================================================
 *
 *       Filename:  JumpGame.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/01/2014 03:18:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LiuYi (), swliuyi@gamil.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

class Solution {
    public:
        bool canJump(int A[], int n) {

            if( n == 1 )
            {
                return true;
            }

            int maxlen = A[0];

            for( int i = 1 ; i < n ; i++ )
            {

                if( i + maxlen > n-1 )
                {
                    return true;
                }

                if( maxlen <= 0 )
                {
                    return false;
                }
                maxlen = maxlen-1 > A[i] ? maxlen-1:A[i];
            }
            return false; 
        }
};
