class Solution {
public:
    int uniquePaths(int m, int n) {
        
        if (m == 0 || n == 0) return 0;
        vector<int> tmp(n,1);
        for (int i=1; i < m ; i++)
        {
            for (int j = 1; j < n; j++)
            {
                tmp[j] += tmp[j-1];
            }
        }
        return tmp[n-1];
    }
};//滚动数组
