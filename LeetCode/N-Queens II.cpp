/*
 * =====================================================================================
 *
 *       Filename:  N-Queens II.cpp
 *
 *    Description: LeetCode 
 *
 *
 *        Version:  1.0
 *        Created:  03/31/2014 05:55:21 PM
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
using namespace std;

class Solution {
    public:

        bool check(vector<int> arr, int pos, int num)
        {
            for( int j = 0 ; j < pos ; j++ )
            {
                if( arr[j] == num || arr[j] + j == num + pos || arr[j] - j == num - pos )
                {
                    return 0;
                }
            }
            return 1;
        }

        void nq( vector<int> arr, int n, int deep , int &res)
        {
            if( deep == n )
            {
                res++;
                return;
            }

            for( int i = 0 ; i < n ; i++ )
            {
                if(check(arr, deep, i))
                {
                    arr[deep] = i;
                    nq(arr, n, deep + 1, res);
                }
            }
        }

        int totalNQueens(int n) {
            vector<int> arr(n, 0);
            int res = 0;
            nq(arr, n, 0, res);
            return res;
        }
};
