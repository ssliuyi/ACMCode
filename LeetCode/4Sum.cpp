class Solution {
    public:
         vector<vector<int> > fourSum(vector<int> &num, int target) {
            vector<vector<int> > res;
            if( num.size() < 4 )
            {
                return res;
            }
            vector<int> arr = num;
            sort(arr.begin(), arr.end());
            for( int i = 0 ; i < arr.size()-3 ; i++ )
            {
                if(i > 0 && arr[i] == arr[i-1])
                  continue;
                for( int j = i+1 ; j < arr.size()-2 ; j++ )
                {
                    if(j > i+1 && arr[j] == arr[j-1])
                      continue;
                    int p = j+1;
                    int q = arr.size()-1;
                    while(p < q)
                    {
                        if (p > j + 1 && arr[p] == arr[p-1])
                        {
                            p++;
                            continue;
                        }
                        if (q < arr.size() - 1 && arr[q] == arr[q+1])
                        {
                            q--;
                            continue;
                        }
                        int sumtmp  = arr[i] + arr[j] + arr[p] + arr[q] ;
                        if (sumtmp == target)
                        {
                            vector<int> tmp;
                            tmp.push_back(arr[i]);
                            tmp.push_back(arr[j]);
                            tmp.push_back(arr[p]);
                            tmp.push_back(arr[q]);
                            res.push_back(tmp);
                            p++;
                        }
                        else if( sumtmp < target )
                        {
                            p++;
                        }
                        else
                        {
                            q--;
                        }
                    }
                }

            }
            return res;
        }
};
