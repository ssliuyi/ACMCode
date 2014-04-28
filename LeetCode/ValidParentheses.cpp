/*
 * =====================================================================================
 *
 *       Filename:  ValidParentheses.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/27/2014 08:57:38 PM
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
#include <stack>
using namespace std;
class Solution {
public:
    char transform(char ch)
    {
        if( ch == '(' )
        {
            return ')';
        }
        else if( ch == '[' )
        {
            return ']';
        }
        else if( ch == '{' )
        {
            return '}';
        }
    }

    bool isValid(string s) {
        stack<char> st;
        for( int i = 0 ; i < s.size() ; i++ )
        {
            if( s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else
            {
                if( st.size() != 0 && transform(st.top()) == s[i] )//st.size() != 0 is important
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if( st.size() == 0 )//important
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
//注意‘]’
