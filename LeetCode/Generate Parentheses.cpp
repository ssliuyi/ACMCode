/*
 * =====================================================================================
 *
 *       Filename:  GP.cpp
 *
 *    Description:  LeetCode
 *
 *        Version:  1.0
 *        Created:  03/29/2014 04:06:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include<iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    void gp(vector<string> & res, int n, int left, int right, string  tmp)
    {
       if( left > n )
       {
           return;
       }
       if( right > left )
       {
           return;
       }
       if( right == left && left == n ) 
       {
           res.push_back(tmp);
       }

       gp(res, n, left+1, right, tmp.append("("));
       tmp.erase(tmp.size()-1);
       gp(res, n, left, right+1, tmp.append(")"));
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string tmp;
        gp(res, n, 0, 0, tmp);
        return res;
    }
};

int main( )
{
       Solution s;
    
       for (int j = 0; j < 5 ; j++)
       {
           vector<string> res;
           res = s.generateParenthesis(j);
           for( int i=0 ; i < res.size() ; i++ )
           {
               cout<<res[i]<<" ";
           }
           cout<<endl;
       }
       return 0;
}
