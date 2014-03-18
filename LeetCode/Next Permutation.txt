class Solution {
public:
    void swap(vector<int>& num,int x,int y)
    {
        int temp=num.at(x);
        num.at(x)=num.at(y);
        num.at(y)=temp;
    }
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.size()==0||num.size()==1) return;
        if(num.size()==2) return swap(num,0,1);
        int m=num.size()-1;
        int n=m-1;
        for(;m>0&&num.at(m)<=num.at(n);m--,n--);
        if(m==0)
        {
            for(int i=0,j=num.size()-1;i<j;i++,j--) swap(num,i,j);
            return;
        }
        else
        {
            int i;
            for(i=num.size()-1;i>n&&num.at(i)<=num.at(n);i--);
            swap(num,i,n);
            for(int i=n+1,j=num.size()-1;i<j;i++,j--) swap(num,i,j);
        } 
    }
};