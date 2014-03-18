class Solution {
public:
    void insert(int arr[],int m,int num)
    {
        int i;
        for(i=m-1;i>=0;i--)
        {
           if(arr[i]>num)
           {
               arr[i+1]=arr[i];
           }
           else
           {
               arr[i+1]=num;
               return;
           }
        }
        if(i<0) arr[0]=num;
    }
   /* int bin_ser(int arr[],int f1,int l1,int num)
    {
        int f=f1,l=l1;
        int mid=(f+l)/2;
        if(arr[mid]>num && arr[mid+1] <=num ) return mid;
        if(arr[mid]>num) bin_ser(arr,)
    }
    */
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for(int i=0;i<n;i++)
        {
            insert(A,m+i,B[i]);
        }
    }
};