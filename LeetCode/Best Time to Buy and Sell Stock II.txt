class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int result=0;
        if(prices.size()==0||prices.size()==1) return 0;
        for(int i=0;i<prices.size()-1;i++)
        {
            int profit=prices[i+1]-prices[i];
            if(profit>0)
            {
                result+=profit;
            }
        }
        return result;
    }
};