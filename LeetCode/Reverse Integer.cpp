class Solution {
public:
    int reverse(int x) 
    {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool ispositive=1;
        if(x<0)
        {
	      ispositive=0;
	       x=-x;
        }
        int result =0;
    	while(x!=0)
    	{
    	    result *= 10;
    	    result += x%10;
    	    x/=10;
    	}
    	if(ispositive)
    		return result;
    	else
    		return -result;
    }
};