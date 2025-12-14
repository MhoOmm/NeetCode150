class Solution {
public:
    vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        int minutes=0;

        queue<pair<int,int>>q;
        int freshorg = 0;
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    freshorg++;
                }else if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        if (freshorg == 0) return 0;

        while(!q.empty())
        {
            int size = q.size();
            while(size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for(auto &dir:directions)
                {
                    int ni = i+dir[0];
                    int nj = j+dir[1];
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m &&
                       grid[ni][nj] == 1) {

                        grid[ni][nj] = 2;
                        freshorg--;
                        q.push({ni, nj});
                    }
                }

            }
            minutes++;
        }

        return freshorg==0 ? minutes-1:-1;
    }
};