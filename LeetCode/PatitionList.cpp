#include<iostream>
using namespace std;

class Solution {
    public:
        int removeDuplicates(int A[], int n) {
            int p1 = 0, p2 = 0;
            if(n == 0)
              return 0;
            while(p1 < n)
            {
                if (A[p1] == A[p2] )
                {
                    p1++;
                }
                else
                {
                    A[p2+1] = A[p1];
                    p2++;
                    p1++;
                }
            }
            return p2+1;
        }
};

int main()
{
    Solution s;
    int A[6] = {1, 1, 2, 3, 3, 4};
    int n = s.removeDuplicates(A, 6);
    for (int i=0; i<n; i++) cout<<A[i]<<endl;
}
