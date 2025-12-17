class Solution {
public:
    int maxArea;
    int n,m;
    vector<vector<int>>directions{{0,-1},{1,0},{-1,0},{0,1}};
    void bfs(queue<pair<int,int>>&q,vector<vector<int>>& grid)
    {
        int count =1;
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            for(auto &dir:directions){
                int ni = curr.first + dir[0];
                int nj = curr.second + dir[1];
                if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]==1)
                {
                    q.push({ni,nj});
                    grid[ni][nj]=0;
                    count+=1;
                }
            }
        }
        maxArea = max(maxArea,count);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n  = grid.size();
        m = grid[0].size();
        queue<pair<int,int>>q;
        maxArea = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    grid[i][j] = 0;
                    q.push({i,j});
                    bfs(q,grid);
                }
            }
        }

        return maxArea;   
    }
};
