const double INF = 1E9;
class Solution {
    public:
        int maxPoints(vector<Point> &points)
        {
            if(!points.size())
              return 0;
            int mans = 1;
            for(int i = 0; i < points.size(); i ++)
            {
                int dup = 0, ans = 1;
                unordered_map<double, int> mp;
                Point p = points[i];
                for(int j = 0; j < points.size(); j ++)
                {
                    if(j == i) continue;
                    Point p2 = points[j];
                    if(p2.x == p.x && p2.y == p.y)
                    {
                        dup++;
                        continue;
                    }
                    if(p2.x-p.x == 0)
                    {
                        if(mp.find(INF) == mp.end())
                          mp[INF] = 2;
                        else
                          mp[INF] += 1;
                        ans = max(ans, mp[INF]);
                    }
                    else
                    {
                        double k = (p2.y-p.y)*1.0/(p2.x-p.x);
                        if(mp.find(k) == mp.end())
                          mp[k] = 2;
                        else
                          mp[k] += 1;
                        ans = max(ans, mp[k]);
                    }
                }
                mans = max(mans, ans+dup);
            }        
            return mans;
        }
};
