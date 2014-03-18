class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int temp=0,maxsum=A[0];
        for(int i=0;i<n;i++)
        {
            temp+=A[i];
            if(temp>maxsum)
            {
                maxsum=temp;
            }
            if(temp<0)
            {
                temp=0;
            }
        }
        return maxsum;
    }
};