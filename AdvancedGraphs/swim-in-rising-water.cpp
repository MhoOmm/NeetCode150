class Solution {
public:
    typedef pair<int,pair<int,int>> pp;
    vector<vector<int>>directions{{0,1},{1,0},{0,-1},{-1,0}};
    bool isSafe(int i,int j,int m,int n)
    {
        return (i>=0 && j>=0 && i<m && j<n);
    }
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.size();

        priority_queue<pp,vector<pp>,greater<pp>>pq;
        vector<vector<int>>result(m,vector<int>(n,INT_MAX));

        pq.push({grid[0][0], {0,0}});// {time,{i,j}}
        result[0][0] = grid[0][0];
        
        while(!pq.empty())
        {
            int currTime = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            if(i==m-1 && j==n-1)
            {
                return result[m-1][n-1];
            }

            for(auto &dir:directions)
            {
                int ni = i+dir[0];
                int nj = j+dir[1];
                if(isSafe(ni,nj,m,n))
                {
                    int nwt = max(currTime, grid[ni][nj]);
                    if(nwt < result[ni][nj])
                    {
                        result[ni][nj] = nwt;
                        pq.push({nwt,{ni,nj}});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};
