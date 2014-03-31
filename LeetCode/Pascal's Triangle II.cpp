class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1);
        while(rowIndex--)
        {
            int temp1,temp2;
            if(res.size()==1)
            {
                res.push_back(1);
                continue;
            }
            else
            {
                int p = 1;
                temp1 = res[0];
                while(p < res.size())
                {
                    temp2 = res[p];
                    res[p] += temp1;
                    temp1 = temp2;
                    p++;
                }
                res.push_back(1);
            }
        }
        return res;
    }
};
