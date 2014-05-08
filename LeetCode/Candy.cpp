/*
 * =====================================================================================
 *
 *       Filename:  Candy.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/04/2014 11:25:39 AM
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
    int candy(vector<int> &ratings) {
        vector<int> candy;
        int res = 0;
        candy.assign(ratings.size(), 1);
        for( int i = 0 ; i < ratings.size()-1 ; i++ )
        {
            if( ratings[i+1] > ratings[i] )
            {
                candy[i+1] = candy[i]+1;
            }
        }
        for( int i = ratings.size()-1 ; i > 0 ; i-- )
        {
            if( ratings[i-1] > ratings[i] )
            {
                candy[i-1] = max(candy[i]+1, candy[i-1]);//important
            }
        }
        for( int i = 0 ; i < candy.size() ; i++ )
        {
            res += candy[i];
        }
        return res;
    }
};
