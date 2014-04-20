/*
 * =====================================================================================
 *
 *       Filename:  1250.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/20/2014 07:47:01 PM
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
void getnext(int * A, string str)
{
    int i = 0;
    int j = 1;
    A[i] = -1;
    while( j < str.length() )
    {
        if( str[i] == str[j] )
        {
            A[j] = i;
            i++;
            j++;
        }
        else if( str[j] == str[0] )
        {
            A[j] = i;
            i = 1;
            j++;
        }
        else
        {
            A[j] = i;
            i = 0;
            j++;
        }
    }
}


int main(int argc, char *argv[])
{
    int num = 0;
    cin>>num;
    for( int i = 0 ; i < num ; i++ )
    {
        string str;
        cin>>str;
        string strs;
        strs.assign(str.rbegin(), str.rend());
        int * A = new int [str.length()];
        getnext(A, strs);
        int j=0, k=0;
        while(j < str.length())
        {
            if( str[j] == strs[k] || k == -1)
            {
                j++;
                k++;
            }
            else
            {
                k = A[k];
            }
        }
        cout<<str.length() - k <<endl;
        delete []A;
    }
}
