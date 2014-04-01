#include <iostream>
using namespace std;

class Solution {
public:

    bool canJump(int A[], int n) {
        int * dp = new int[n]{0};
        if( n ==0 )
        {
            return false;
        }
        dp[n-1] = 1;
        for( int i = n-2 ; i >= 0 ; i-- )
        {
            for( int j = 0 ; j < A[i] ; j++ )
            {
                if( dp[i+j] == 1)
                {
                    break;
                }
            }
        }
        if( dp[0] == 1 )
        {
           return true; 
        }
        return false;
    }
};
