/*
 * =====================================================================================
 *
 *       Filename:  Count and Say.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/14/2014 10:50:03 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LiuYi (), swliuyi@gamil.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;
class Solution {
    public:
        string countAndSay(int n) {
            string pre = "1";
            if( n == 1 )
            {
                return pre;
            }
            else
            {
                for( int i = n ; i > 1 ; i-- )
                {
                    int x = 0;
                    int y = 0;
                    int num = 0;
                    string cur;
                    while( y < pre.size())
                    {
                        if( pre[x] == pre[y] )
                        {
                            num++;
                            y++;
                        }
                        else
                        {
                            cur = cur + char(num + '0');
                            cur = cur + pre[x];
                            num = 0;
                            x = y;
                        }
                    }
                    if( x != y )
                    {
                        cur = cur + char(num + '0');
                        cur = cur + pre[x];
                        num = 0;
                        x = y;
                    }
                    pre = cur;
                }
            }
            return pre;
        }
};
