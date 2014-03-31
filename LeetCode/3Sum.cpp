/*
 * =====================================================================================
 *
 *       Filename:  3Sum.cpp
 *
 *    Description:  LeetCode
 *
 *        Version:  1.0
 *        Created:  03/31/2014 11:10:59 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LiuYi (), swliuyi@gamil.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {

        vector<vector<int> > res;

        if( num.size() < 3 )
        {
            return res;
        }

        sort(num.begin(), num.end());

        for( int i = 0 ; i < num.size()-2 ; i++ )
        {
            if( i > 0 && num[i] == num[i-1] )
            {
                continue;
            }
            int p = i + 1;
            int q = num.size() - 1;
            while( p < q )
            {

                if( p > i + 1 && num[p] == num[p-1] )
                {
                    p++;
                    continue;
                }

                if( q < num.size()-1 && num[q+1] == num[q]  )
                {
                    q--;
                    continue;
                }

                vector<int> sumtmp;

                int sum = num[i] + num[p] + num[q];

                if( sum == 0 )
                {
                   sumtmp.push_back(num[i]);
                   sumtmp.push_back(num[p]);
                   sumtmp.push_back(num[q]);
                   res.push_back(sumtmp);
                   p++;
                }

                if( sum < 0 )
                {
                    p++;
                }

                if( sum > 0 )
                {
                    q--;
                }
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> num;
    num.push_back(0);
    num.push_back(0);
    num.push_back(0);
    num.push_back(0);
    vector<vector<int> > res = s.threeSum(num);

    for( int i = 0 ; i < res.size() ; i++ )
    {
        for( int j = 0 ; j < res[i].size() ; j++ )
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
