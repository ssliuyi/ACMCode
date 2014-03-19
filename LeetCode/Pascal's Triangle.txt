class Solution {
private:
     vector<vector<int> > res;
public:
    vector<vector<int> > generate(int numRows) {
        res.clear();
        if (numRows == 0)
            return res;
        vector<int> tmp;
        tmp.push_back(1);
        res.push_back(tmp);
        while(--numRows)
        {
            int temp1,temp2;
            if(tmp.size()==1)
            {
                tmp.push_back(1);
                res.push_back(tmp);
                continue;
            }
            else
            {
                temp1 = tmp[0];
                for (int p = 1; p < tmp.size(); p++)
                {
                    temp2 = tmp[p];
                    tmp[p] += temp1;
                    temp1 = temp2;
                }
                tmp.push_back(1);
                res.push_back(tmp);
            }
        }
        return res;
    }
};//please notice the res.clear(), if not,  it will not satisfine the memory limit
