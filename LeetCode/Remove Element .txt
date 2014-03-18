class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(n==0) return 0;
        int i=0;
        int j=0;
        int temp=0;
        while(i<n)
        {
            if(A[i]!=elem)
            {
                A[j]=A[i];
                j++;
            }
            i++;
        }
        return j;
    }
};