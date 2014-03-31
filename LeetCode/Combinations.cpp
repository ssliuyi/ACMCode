/*
 * =====================================================================================
 *
 *       Filename:  Combinations.cpp
 *
 *    Description:  LeetCode
 *
 *        Version:  1.0
 *        Created:  03/31/2014 01:12:35 PM
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
    void cb(vector<vector<int> > &res, vector<int> arr,vector<int> & tmpres,  int from, int num)
    {
        if( num == tmpres.size() )
        {
            res.push_back(tmpres);
            return;
        }

        for( int i = from ; i < arr.size() ; i++ )
        {
            tmpres.push_back(arr[i]);
            cb(res, arr, tmpres, i+1, num);
            tmpres.erase(tmpres.end()-1);
        }
        
    }
    vector<vector<int> > combine(int n, int k) {
        
        vector<vector<int> > res;
        vector<int> tmpres;
        vector<int> arr;
        for( int i = 0 ; i < n ; i++ )
        {
            arr.push_back(i+1);
        }
       cb(res,arr,tmpres, 0, k);
       return res;
    }
};
