/*
 * =====================================================================================
 *
 *       Filename:  DistinctSubsequences.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/29/2014 10:56:34 PM
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
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
    public:
        int numDistinct(string S, string T) {
            map < char, vector<int> > dic;
            vector<int> dp_pre;
            vector<int> dp_cur;
            for( int i = 0 ; i < T.size() ; i++ )
            {
                if( dic.count(T[i]) == 0 )
                {
                    dic[T[i]];
                }
            }

            for( int i = 0 ; i < S.size() ; i++ )
            {
                if( dic.count(S[i]) != 0 )
                {
                    dic[S[i]].push_back(i);
                }
            }

            
            for( int i = 0 ; i < dic[T[0]].size() ; i++ )
            {
                dp_pre.push_back(1);
            }

            if( T.size() == 1 )
            {
                dp_cur = dp_pre;
            }

            for( int i = 1 ; i < T.size() ; i++ )
            {
                for( int k = 0 ; k < dic[T[i]].size() ; k++ )
                {
                    dp_cur.push_back(0);
                    for( int j = 0 ; j < dic[T[i-1]].size() ; j++ )
                    {
                        if( dic[T[i-1]][j] < dic[T[i]][k]   )
                        {
                            dp_cur[k] += dp_pre[j];
                        }
                    }
                }
                dp_pre = dp_cur;
                if( i != T.size() - 1 )
                {
                    dp_cur.clear();
                }
            }
            int res = 0;
            for( int i = 0 ; i < dp_cur.size() ;i++ )
            {
                res += dp_cur[i];
            }
            return res;
        }
};
int main(int argc, char *argv[])
{
    Solution s;
    cout<<s.numDistinct("b" , "b")<<endl;
}
