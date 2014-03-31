class Solution {
public:
    void swap(int & a, int & b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    void p(vector<int> &num , vector<vector<int> > &res ,int k)
    {
        if (k == num.size()-1)
        {
            res.push_back(num);
            return;
        }
        else
        {
            for (int i = k; i<num.size(); i++)
            {
                swap(num[k],num[i]);
                p(num,res,k+1);
                swap(num[k],num[i]);
            }
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        p(num,res,0);
        return res;
    }
};
