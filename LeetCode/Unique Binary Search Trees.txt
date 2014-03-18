class Solution {
public:
    int numTrees(int n) {
        int result=0;
        if(n==0) return 1;
        if(n==1) return 1;
        for(int i=0;i<n;i++)
        {
            result += numTrees(i)*numTrees(n-1-i);
        }
        return result;
    }
};