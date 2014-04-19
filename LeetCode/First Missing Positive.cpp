/*
 * =====================================================================================
 *
 *       Filename:  First Missing Positive.cpp
 *
 *    Description:  leetcode
 *
 *        Version:  1.0
 *        Created:  04/19/2014 05:19:45 PM
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
        int firstMissingPositive(int A[], int n) {
            int i = 0;
            while( i < n )
            {
                if( A[i] != i+1 && A[i] < n + 1 && A[i] > 0 && A[A[i]-1] != A[i])
                {
                    int temp = A[A[i]-1];
                    A[A[i]-1] = A[i];
                    A[i] = temp;
                }
                else
                {
                    i++;
                }
            }
            for( int j = 0 ; j < n ; j++ )
            {
                if( A[j] != j+1 )
                {
                    return j+1;
                }
            }
            return n+1; 
        }
};
