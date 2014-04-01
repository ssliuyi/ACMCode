/*
 * =====================================================================================
 *
 *       Filename:  3Sum Closest.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/01/2014 04:52:44 PM
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
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) 
    {
        sort(num.begin(), num.end());
        int minerror = num[0]+num[1]+num[2] - target;
        for( int i = 0 ; i < num.size() ; i++ )
        {
            if( i > 0 && num[i] == num[i-1] )
            {
                continue;
            }
            int p = i+1;
            int q = num.size() - 1;
            while( p < q )
            {
                if( p > i +1 && num[p] == num[p-1] )
                {
                    p++;
                    continue;
                }

                if( q < num.size() -1 &&  num[q] == num[q+1] )
                {
                    q--;
                    continue;
                }

                int sum = num[i] + num[p] + num[q]; 

                if( abs(sum - target) < abs(minerror) )
                {
                    minerror = sum - target;
                }

                if( sum - target  == 0)
                {
                    return target;
                }

                if( sum - target > 0 )
                {
                    q--;
                }

                if( sum - target < 0 )
                {
                    p++;
                }
            }
        }
            return minerror + target;
    }
};
int main(int argc, char *argv[])
{
    Solution s;
    vector<int> num;
    num.push_back(1);
    num.push_back(1);
    num.push_back(1);
    num.push_back(0);
    cout<<s.threeSumClosest(num,100)<<endl;
}
