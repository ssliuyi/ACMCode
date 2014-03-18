class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m=grid.size();
        int n=grid.at(0).size();
        int **arr=new int * [m];
        for(int i=0;i<m;i++) arr[i]=new int[n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                arr[i][j]=0;
            }
        }
        arr[0][0]=grid[0][0];
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i<m-1)
                {
                    if(arr[i+1][j]==0) arr[i+1][j]=arr[i][j]+grid[i+1][j];
                    else if(arr[i+1][j]>arr[i][j]+grid[i+1][j]) arr[i+1][j]=arr[i][j]+grid[i+1][j];
                }
                if(j<n-1)
                {
                    if(arr[i][j+1]==0) arr[i][j+1]=arr[i][j]+grid[i][j+1];
                    else if(arr[i][j+1]>arr[i][j]+grid[i][j+1]) arr[i][j+1]=arr[i][j]+grid[i][j+1];
                }
            }
        }
        return arr[m-1][n-1];
    }
};