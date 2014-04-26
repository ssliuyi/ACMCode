/*
 * =====================================================================================
 *
 *       Filename:  kuohao.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/26/2014 10:32:40 PM
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
void par(vector<string> &res,string &ans, int maxnum, int left, int right)
{
    if( left == right && left == maxnum )
    {
        res.push_back(ans);
        return;
    }

    if( left < maxnum )
    {
        ans[right+left] = '(';
        par(res, ans, maxnum, left+1, right);
    }

    if( right < left )
    {
        ans[right + left ] =   ')';
        par(res, ans, maxnum, left, right+1);
    }

}

int main(int argc, char *argv[])
{
    vector<string> res;
    string ans(6, ' ');
    par(res,ans, 3, 0, 0); 
    for( int i = 0 ; i < res.size() ; i++ )
    {
        cout<<res[i]<<endl;
    }

}
