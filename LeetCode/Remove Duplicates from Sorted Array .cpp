class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n==0) return NULL;
        int result=1;
        int i=1,j=1;
        int temp=A[0];
        while(i<n)
        {
            if(A[i]!=temp)
            {
                temp=A[i];
                A[j]=A[i];
                i++;
                j++;
                result++;
            }
            else i++;
        }
        return result;
    }
};