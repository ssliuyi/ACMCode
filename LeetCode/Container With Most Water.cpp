#include<iostream>
using namespace std;

class Solution {
    public:
        int longestValidParentheses(string s) {
            int len = s.size();
            int *dp = new int [len]();
            int max = 0;
            for( int i = len - 1 ; i >= 0 ; i-- )
            {
                int j = i + 1 + dp[i + 1];
                if( s[i] == '(' )
                {
                    if( j < len && s[j] == ')')
                    {
                        dp[i] = dp[i+1] + 2;
                        if( j + 1 < len )
                        {
                            dp[i] += dp[j+1];
                        }
                    }
                }
                if( max < dp[i] )
                {
                    max = dp[i];
                }
            }
            return max;

        }
};
