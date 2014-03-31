class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> result;
        for(int i=0;i<numbers.size();i++)
        {
            if(number.at(i)>target) continue;
            for(int j=0;j<i;j++)
            {
                if(number.at(i)+number.at(j)==target)
                {
                    result.push_back(j+1);
                    result.push_back(i+1);
                    return result;
                }
            }
        }
    }
};