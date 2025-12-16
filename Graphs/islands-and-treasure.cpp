class Solution {
public:
    vector<vector<int>>directions{{0,1},{1,0},{-1,0},{0,-1}};
    int n,m;
    void bfs(queue<pair<int,int>>&q,vector<vector<int>>& grid){
        int dist = 1;
        while(!q.empty())
        {
            int size = q.size();
            while(size--){
                auto curr = q.front();
                q.pop();
                for(auto &dir:directions){
                    int ni = curr.first + dir[0];
                    int nj = curr.second + dir[1];

                    if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]== 2147483647){
                        grid[ni][nj] = dist;
                        q.push({ni,nj});
                    }
                }
            }
            dist++;
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>result=grid;

        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 0)
                {
                    q.push({i,j});
                    grid[i][j] = 0;
                }
            }
        }

        bfs(q,grid);
    }
};
