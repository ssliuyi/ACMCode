class Solution {
public:
    int bsl(int A[],int f,int l,int tar)
    {
        int m=(f+l)/2;
        if(f>l) return -1;
        if(A[m]==tar&&(m==0||A[m-1]<tar))return m;
        else if(A[m]<tar) return bsl(A,m+1,l,tar);
        else if(A[m]>=tar) return bsl(A,f,m-1,tar);
    }
    int bsr(int A[],int n,int f,int l,int tar)
    {
        int m=(f+l)/2;
        if(f>l) return -1;
        if(A[m]==tar&&((m==n-1)||A[m+1]>tar))return m;
        else if(A[m]<=tar) return bsr(A,n,m+1,l,tar);
        else if(A[m]>tar) return bsr(A,n,f,m-1,tar);
    }
    
    vector<int> searchRange(int A[], int n, int target) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        //int x=bs(A,0,n-1,target);
        vector<int> result;
        result.push_back(bsl(A,0,n-1,target));
        result.push_back(bsr(A,n,0,n-1,target));
        return result;
    }
};