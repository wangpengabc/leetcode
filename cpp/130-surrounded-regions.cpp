// https://leetcode.cn/problems/surrounded-regions/description/
// dfs \ bfs

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        // label all the edge 'o' in the left column and right column
        for (int i=0; i<m; i++) {
            dfs(board, i, 0);
            dfs(board, i, n-1);
        }

        // label all the edge 'o' in the top and bottom row
        for (int j=1; j<n-1; j++) {
            dfs(board, 0, j);
            dfs(board, m-1, j);
        }

        // for (int i=0; i<m; i++) {
        //     for (int j=0; j<n; j++) {
        //         cout << board[i][j] << " ";
        //     }
        // }

        // find all the reserved 'o' and label with 'X'
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == 'l') {
                    board[i][j] = 'O';
                }
            }
        }

    }

    void dfs(vector<vector<char>>& board, int row, int col) {
        int m = board.size();
        int n = board[0].size();
        if (row >= m || col >= n || row < 0 || col < 0) {
            return;
        }
        if (board[row][col] == 'O') {
            board[row][col] = 'l';
            dfs(board, row-1, col);
            dfs(board, row, col-1);
            dfs(board, row+1, col);
            dfs(board, row, col+1);
        }
    }
};
