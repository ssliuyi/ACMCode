class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(digits.size()==0) return digits;
        int temp=1;
        for(int i=digits.size()-1;i>=0;i--)
        {
            if(digits.at(i)+temp==10)
            {
                digits.at(i)=0;
            }
            else
            {
                digits.at(i)+=1;
                break;
            }
        }
        int temp2=0;
        int temp3=0;
        if(digits.at(0)==0)
        {
            temp2=digits.at(0);
            digits.at(0)=1;
            for(int i=1;i<digits.size();i++)
            {
                temp3=digits.at(i);
                digits.at(i)=temp2;
                temp2=temp3;
            }
            digits.push_back(temp2);
        }
        return digits;
    }
   
};