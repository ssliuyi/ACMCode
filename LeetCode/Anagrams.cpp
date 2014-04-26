/*
 * =====================================================================================
 *
 *       Filename:  Anagrams.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/25/2014 09:00:49 PM
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
#include <string>
#include <algorithm>
#include <map>

using namespace std;
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector <string> tmp = strs;
        map <string, int> dic;
        vector<string> res;
        for( int i = 0 ; i < tmp.size() ; i++ )
        {
            sort(tmp[i].begin(), tmp[i].end());
            if( dic.count(tmp[i]) == 0 )
            {
                dic[tmp[i]] = i;
            }
            else
            {
                if( dic[tmp[i]] != -1 )
                {
                    res.push_back(strs[dic[tmp[i]]]);
                    dic[tmp[i]] = -1;
                }
                res.push_back(strs[i]);
            }
        }
        return res;
    }
};
