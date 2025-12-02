class Solution {
public:
    int n ,m;
    vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
    bool find(int i,int j,int idx,vector<vector<char>>& board, string word){
        if(idx == word.length())return true;

        if(i<0||i>=n||j<0||j>=m|| board[i][j]=='AA')
        {
            return false;
        }

        if(board[i][j]!=word[idx])return false;

        // check all possibilities
        char temp = board[i][j];
        board[i][j] = 'AA';
        for(auto &dir:directions){
            int ni = i+dir[0];
            int nj = j+dir[1];
            if(find(ni,nj,idx+1,board,word)){
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {

        n = board.size();
        m = board[0].size();

        for(int i = 0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == word[0] && find(i,j,0,board,word))
                {
                    return true;
                }
            }
        }

        return false;
        
    }
};
