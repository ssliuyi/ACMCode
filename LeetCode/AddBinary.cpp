/*
 * =====================================================================================
 *
 *       Filename:  AddBinary.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/25/2014 08:02:50 PM
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
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {


        if( a.length() > b.length() )
        {
            string tmp = a;
            a = b;
            b = tmp;
        }
        
        string zero = "0";

        while( a.length() != b.length() )
        {
            a = zero + a;
        }


        int len = b.length();
        int carry = 0;

        string res = "";
        for( int i = 1 ; i <= len ; i++ )
        {
            int cur = 0;
            cur = a[len-i] - '0' + b[len-i] - '0' + carry;
            if( cur > 1 )
            {
                cur -= 2;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            char tmp = cur + '0';
            res = tmp + res; 
        }

        if( carry != 0 )
        {
            char tmp = carry + '0';
            res = tmp + res;
        }

        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    string a = "1010";
    string b = "1011";
    cout<<s.addBinary(a,b)<<endl;
}
