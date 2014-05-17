/*
 * =====================================================================================
 *
 *       Filename:  Decode Ways.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/14/2014 10:57:23 AM
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
using namespace std;
class Solution {
    public:
        int numDecodings(string s) {
            if( s.size() == 0 )
            {
                return 0;
            }
            vector<int> arr;
            arr.assign(s.size()+1, 1);
            if(s[s.size()-1] == '0')//注意为0的情况
            {
                arr[s.size()-1] = 0;
            }
            for( int i = s.size()-2 ; i >= 0 ; i-- )
            {
                if(s[i] == '0')//注意为0的情况
                {
                    arr[i] = 0;
                    continue;
                }
                int tmp = atoi(s.substr(i, 2).c_str());
                if(tmp  >=1 && tmp <= 26)
                {
                    arr[i] = arr[i+1] + arr[i+2];
                }
                else
                {
                    arr[i] = arr[i+1];
                }
            }
            return arr[0];
        }
};
