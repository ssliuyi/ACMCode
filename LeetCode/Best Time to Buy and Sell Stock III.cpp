/*
 * =====================================================================================
 *
 *       Filename:  Best Time to Buy and Sell Stock III.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/30/2014 10:37:40 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LiuYi (), swliuyi@gamil.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int profit = 0, n = prices.size();
        if (n == 0) {
            return 0;
        }
        int l[n], r[n];
        l[0] = 0;
        r[n-1] = 0;
        int minp = prices[0];
        for (int i = 1; i < n; i++) {
            l[i] = max(prices[i] - minp , l[i - 1]);        
            minp = min(prices[i] , minp);
        }
        int maxp = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            r[i] = max(maxp - prices[i] , r[i + 1]);
            maxp = max(prices[i] , maxp);
        }
        for (int i = 0; i < n; i++) {
            profit = max(l[i] + r[i] , profit);
        }
        return profit;      
    }
};
