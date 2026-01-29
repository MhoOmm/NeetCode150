class Solution {
public:
    int n;

    void solve(vector<string>& board, int row, vector<vector<string>>& result,
               unordered_set<int>& diag, unordered_set<int>& cols, unordered_set<int>& antiD) {

        if(row >= n) {
            result.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++) {
            int d = row + col;   
            int a = row - col;      

            if(cols.count(col) || diag.count(d) || antiD.count(a))
                continue;

            board[row][col] = 'Q';
            cols.insert(col);
            diag.insert(d);
            antiD.insert(a);

            solve(board, row + 1, result, diag, cols, antiD);
            board[row][col] = '.';
            cols.erase(col);
            diag.erase(d);
            antiD.erase(a);
        }
    }

    vector<vector<string>> solveNQueens(int N) {
        n = N;
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> result;

        unordered_set<int> diag;
        unordered_set<int> antiD;
        unordered_set<int> cols;

        solve(board, 0, result, diag, cols, antiD);

        return result;
    }
};