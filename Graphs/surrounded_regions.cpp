class Solution {
public:
    vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    int n,m ;
    void bfs(vector<vector<char>>& board,queue<pair<int,int>>&q)
    {
        while(!q.empty())
        {
            int size= q.size();
            while(size--)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for(auto &dir:directions)
                {
                    int ni = i+dir[0];
                    int nj = j+dir[1];
                    if(ni>=0 && nj>=0 && ni<n && nj<m && board[ni][nj]=='O')
                    {
                        board[ni][nj] = 'N';
                        q.push({ni,nj});
                    }
                }

            }

        }
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')
            {
                board[i][0] = 'N';
                q.push({i,0});
            }
            if(board[i][m-1] == 'O')
            {
                board[i][m-1] = 'N';
                q.push({i,m-1});
            }
        }
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O')
            {
                board[0][j]= 'N';
                q.push({0,j});
            }
            if(board[n-1][j] == 'O')
            {
                board[n-1][j] = 'N';
                q.push({n-1,j});
            }
        }

        bfs(board,q);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='N')
                {
                    board[i][j] = 'O';
                }
                else if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
            }
        }
        
    }
};
