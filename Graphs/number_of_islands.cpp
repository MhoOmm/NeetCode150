class Solution {
public:
    vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    void bfs(int i,int j,queue<pair<int,int>>&q,vector<vector<char>>& grid){
        grid[i][j]='9';
        q.push({i,j});

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            for(auto &dir:directions){
                int ni = curr.first+dir[0];
                int nj = curr.second+dir[1];
                if(ni < 0 || ni >= grid.size() || nj < 0 || nj >= grid[0].size() || grid[ni][nj] != '1'){
                    continue;
                }

                q.push({ni,nj});
                grid[ni][nj] ='9';

            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)
            return 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        int noi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    bfs(i,j,q,grid);
                    noi++;
                }
            }
        }

        return noi;
        
    }
};
