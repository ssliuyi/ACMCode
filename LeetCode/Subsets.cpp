class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n=S.size();
        sort(S.begin(),S.end());
        vector<vector<int> > result;
        for(int i=0;i<pow(2,n);i++)
        {
            int temp=i;
            vector<int> t;
            for(int k=0;temp!=0;k++,temp=temp/2)
            {
                if(temp%2) t.push_back(S[k]);
            }
            result.push_back(t);
            t.clear();
        }
        return result;
    }
};