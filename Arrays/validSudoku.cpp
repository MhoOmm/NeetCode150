class Solution {
public:

    bool validsudoku(vector<vector<char>>& board,int sr,int sc,int er,int ec)
    {
        unordered_set<char>st;
        for(int i=sr;i<=er;i++)
        {
            for(int j=sc;j<=ec;j++)
            {
                char ch = board[i][j];
                if(ch =='.'){
                    continue;
                }
                else if(st.find(ch)!=st.end())
                {
                    return false;
                }
                st.insert(ch);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {

        // for unique in every row
        for(int i = 0;i<9;i++)
        {
            unordered_set<char>st;
            for(int j =0 ;j<9;j++)
            {
                if(board[i][j]=='.')continue;
                else if(st.find(board[i][j])!=st.end())
                {
                    return false;
                }
                st.insert(board[i][j]);
            }
        }

        // for unique in every column
        for(int j=0;j< 9;j++)
        {
            unordered_set<char>st;
            for(int i=0;i<9;i++ )
            {
                if(board[i][j]=='.')continue;

                if(st.find(board[i][j])!=st.end())
                {
                    return false;
                }

                st.insert(board[i][j]);
            }
        }

        // for every 3x3 matrix
        for(int sr = 0;sr<9;sr+=3)
        {
            int er=sr+2;
            for(int sc =0;sc<9;sc+=3)
            {
                int ec=sc+2;
                if(!validsudoku(board,sr,sc,er,ec))
                {
                    return false;
                }

            }
        }

        return true;
    }
};
