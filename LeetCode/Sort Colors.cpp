class Solution {
public:
    void swap(int *A,int a,int b)
    {
        int temp=A[a];
        A[a]=A[b];
        A[b]=temp;
    }
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int p0=0,p1=0,p2=n-1;
        while(p1<=p2)
        {
            if(A[p1]==0)
            {
                swap(A,p1,p0);
                p0++;
                p1++;
            }
            else if(A[p1]==1)
            {
                p1++;
            }
            else if(A[p1]==2)
            {
                swap(A,p1,p2);
                p2--;
            }
        }
    }
};