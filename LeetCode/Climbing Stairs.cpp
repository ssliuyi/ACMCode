class Solution {
public:
    int climbStairs(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> v;
        v.push_back(1);
        v.push_back(1);
        while(n >= v.size())
        {
            v.push_back(v[v.size()-1]+v[v.size()-2]);
        }
        return v[n];
    }
};