/*
 * =====================================================================================
 *
 *       Filename:  N-Queens.cpp
 *
 *    Description:  LeetCode
 *
 *        Version:  1.0
 *        Created:  03/31/2014 03:31:33 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LiuYi (), swliuyi@gamil.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
        void nq(vector<vector<string> > & res, vector<int> situation, int deep, int n)
        {
            if( deep == n )
            {
                vector<string> tmp;
                for( int i = 0 ; i < n ; i++ )
                {
                    string a(n, '.');
                    a[situation[i]] = 'Q';
                    tmp.push_back(a);
                }
                //  debug
                //  cout<<tmp.size()<<endl;
                //  cout<<tmp[0].size()<<endl;
                //  for( int i = 0 ; i < tmp.size() ; i++ )
                //  {
                //  for( int j = 0 ; j < tmp[0].size() ; j++ )
                //  {
                //      cout<<tmp[i][j] <<" ";
                //  }
                //  cout<<endl;
                //  }
                //                
                res.push_back(tmp);
                return;
            }

            for( int i = 0 ; i < n ; i++ )
            {
                bool rightpos = 1;
                for( int j = 0 ; j < deep ; j++ )
                {
                    if( situation[j] == i || j + situation[j] == i + deep || j - situation[j] == deep - i)
                    {
                        rightpos = 0;
                        break;
                    }
                }

                if(rightpos == 1)
                {
                    situation[deep] = i;
                    nq(res, situation, deep+1, n);
                }

            }
        }

        vector<vector<string> > solveNQueens(int n) 
        {
            vector<vector<string> > res;
            vector<int> situation(n, 0);
            nq(res, situation, 0, n); 
            return res;
        }
};
int main()
{
    Solution s;
    vector<vector<string> > res = s.solveNQueens(4);
    for( int i = 0 ; i < res.size() ; i++ )
    {
        for( int j= 0 ; j < res[0].size() ; j++ )
        {
                cout<<res[i][j]<<endl;
        }
       cout<<endl; 
    }
    return 0;
}
