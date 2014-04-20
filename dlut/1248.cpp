/*
 * =====================================================================================
 *
 *       Filename:  1248.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/20/2014 07:26:26 PM
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
using namespace std;

int main(int argc, char *argv[])
{
    int n = 0;
    cin>>n;
    for( int i = 0 ; i < n ; i++ )
    {
        string str;
        cin>>str;
        int max = 1;
        int k = 0;
        int j = 0;
        while( j < str.length() )
        {
            if( str[k] == str[j] )
            {
                j++;
                if( max < j - k)
                {
                    max = j - k;
                }
            }
            else
            {
                k = j;
                j++;
            }
        }
        cout<<max<<endl;
    }

}
