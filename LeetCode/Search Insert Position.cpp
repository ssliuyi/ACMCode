#include<iostream>
using namespace std;

class Solution {
public:
    int BS(int A[], int from, int to, int target)
    {
        if(from >= to)
        {
            if(A[from] < target)
              return from + 1;
            return from;
        }
        else
        {
            int middle = (from + to)/2;
            if (A[middle] == target) return middle;
            else if (A[middle] > target) return BS(A, from, middle-1, target);
            else return BS(A,middle+1, to, target);
        }
    }
    int searchInsert(int A[], int n, int target) {
        return BS(A, 0, n-1, target);
    }
};

//自动化测试
//
int main()
{
    Solution s;
    int A[5] = {1, 3, 5, 7, 9};

    for (int i = 0; i < 13 ; i++)
    {
        cout<<s.searchInsert(A, 5, i)<<endl;
    }

    cout<<s.searchInsert(A, 5, 4)<<endl;
    return 0;
}
