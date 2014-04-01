class Solution {
    public:
        string longestCommonPrefix(vector<string> &strs) {
            if( strs.size() == 0 )
            {
                return "";
            }
            string ch = strs[0];
            int common = 0;
            int minlen = strs[0].size();

            for( int i = 0 ; i < strs.size() ; i++ )
            {
                if( minlen > strs[i].size() )
                {
                    minlen = strs[i].size();
                    ch = strs[i];
                }
            }

           for(common = 0 ; common < minlen ; common++ )
           {
               for( int i = 0 ; i < strs.size() ; i++ )
               {
                   if( strs[i][common] != ch[common] )
                   {
                       if( common == 0 )
                       {
                           return "";
                       }
                       else
                       {
                           return ch.substr(0, common);
                       }
                   }
               }
           }
           return ch;
        }
};
