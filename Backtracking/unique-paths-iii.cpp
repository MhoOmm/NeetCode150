class Solution {
public:
    int n,m;
    int result = 0;
    vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
    void solve(int i,int j,int count,int nobs,vector<vector<int>>& grid){
        if(i>=n||j>=m||i<0||j<0||grid[i][j] == -1)
        {
            return ;
        }

        
        if(grid[i][j]==2 && count==nobs){
            result++;
            return;
        }

        int temp = grid[i][j];
        grid[i][j] = -1;
        for(auto &dir:directions)
        {
            int ni = i+dir[0];
            int nj = j+dir[1];
            solve(ni,nj,count+1,nobs,grid);
        }
        grid[i][j] = temp;

    }
    int uniquePathsIII(vector<vector<int>>& grid) {

        n  = grid.size();
        m  = grid[0].size();

        // to count the number of non-obstacles
        int sti,stj;
        int nobs=0;
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(grid[i][j]!=-1){
                    nobs++;
                }
                if(grid[i][j]==1)
                {
                    sti = i;
                    stj = j;
                }
            }
        }
        solve(sti,stj,1,nobs,grid);
        return result;
    }
};