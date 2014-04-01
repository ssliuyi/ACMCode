/*
 * =====================================================================================
 *
 *       Filename:  Count and Say.cpp
 *
 *    Description:  LeetCode
 *
 *        Version:  1.0
 *        Created:  03/31/2014 07:15:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LiuYi (), swliuyi@gamil.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;


class Solution {
    public:
        string countAndSay(int n) {

            string res;
            string pre = "1";

            for( int i = 1 ; i < n ; i++ )
            {
                int cur = 0;
                int dup = 0;
                string ch = pre.substr(0, 1); 
                while( cur < pre.size())
                {
                    string ch = pre.substr(cur, 1); 
                    if( pre.substr(cur, 1) == ch )
                    {
                        dup++;
                    }
                    else
                    {
                        string sdup;
                        stringstream ss;
                        ss<<dup;
                        ss>>sdup;
                        res.append(sdup);
                        res.append(ch);
                        dup = 0;
                    }
                }
                if( dup != 0 )
                {  
                    string sdup;
                    stringstream ss;
                    ss<<dup;
                    ss>>sdup;
                    res.append(sdup);
                    res.append(ch);
                }
                pre = res;
                cur++;
            }
            return res;
        }
};

int main()
{
    Solution s;
    cout<<s.countAndSay(2);
}
