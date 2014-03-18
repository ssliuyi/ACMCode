class Solution {
public:
       int findKth(int A[], int aoffset, int m, int B[],int boffset, int n,int k)
       {
        if(m > n) return findKth(B, boffset, n, A, aoffset, m, k);
        if(m==0)return B[k - 1];
        if(k==1)return A[aoffset]> B[boffset]? B[boffset]:A[aoffset];
        int pa = k/2 > m? m : k/2;
        int pb = k - pa;
        if(A[aoffset + pa - 1] >= B[boffset + pb - 1])
            return findKth(A,aoffset, m, B, boffset + pb, n - pb, k-pb);
        else return findKth(A, aoffset + pa, m - pa, B, boffset, n, k - pa);
        }

        double findMedianSortedArrays(int A[], int m, int B[], int n) 
        {
        int N = m + n;
        if(N%2 == 0){
            return (double)(findKth(A,0,m, B,0,n,N/2) +findKth(A,0,m, B,0,n,N/2 + 1))/(double)2;
        }else {
            return findKth(A,0,m, B,0,n,N/2 + 1);
        }
    }

};