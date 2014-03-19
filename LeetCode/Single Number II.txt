class Solution {
public:
    int singleNumber(int A[], int n) {
        int ones = 0;
        int twos = 0;
        int three = 0;
        for (int i =0; i<n; i++)
        {
            twos |= (ones & A[i]);
            ones ^= A[i];
            three = ~(ones & twos);
            ones &= three;
            twos &= three;
        }
        return ones;
    }
};
