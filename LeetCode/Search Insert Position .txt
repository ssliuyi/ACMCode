class Solution {
public:
    int bs(int A[],int n,int f,int l,int target)
    {
         int m=(f+l)/2;
         if(A[m]==target)return m;
         else if(A[m]>target&&m==0) return 0;
         else if(A[m]<target&&(m==n||A[m+1]>=target)) return m+1;
         if(A[m]>target)
         {
             return bs(A,n,f,l-1,target);
         }
         else
         {
             return bs(A,n,f+1,l,target);
         }
    }
    int searchInsert(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
       return bs(A,n-1,0,n-1,target);
    }
};