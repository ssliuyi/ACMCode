class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
    
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> min;
		vector<vector<int>>::iterator i;
		vector<int>::iterator j;
		int k=0;
		for(i=triangle.begin();i!=triangle.end();i++)
		{
			vector<int> temp;
			for(j=i->begin(),k=0;j!=i->end();j++,k++)
			{
				
				if(min.empty())
				{
					min.push_back(*j);
				}
				else
				{
					
					if(temp.empty())
					{
						temp.push_back(*j+*min.begin());
					}
					else if(temp.size()==i->size()-1)
					{
						temp.push_back(*j+*(--min.end()));
					}
					else
					{
						temp.push_back(*j+min.at(k)<*j+min.at(k-1)?*j+min.at(k):*j+min.at(k-1));
					}
				}

			}
			if(!temp.empty()) min=temp;
		}
		int result=min.at(0);
        for(int s=0;s<min.size();s++)
		{
			if(result>min.at(s))
				result=min.at(s);
		}
		return result;
    }
};