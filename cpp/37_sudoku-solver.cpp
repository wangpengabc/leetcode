// https://leetcode.cn/problems/sudoku-solver/

class Solution {
public:
    // using Pos = vector<int>;
    // using Canadidate = vector<char>;
    // vector<pair<Pos, Canadidate>> construct_candidates(vector<vector<char>>& board) {
    //     vector<pair<Pos, Canadidate>> candidates;

    //     return candidates;
    // }


    vector<vector<char>> origin_board;
    vector<char> candidates{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    void solveSudoku(vector<vector<char>>& board) {
        origin_board = board;
        back_trace(board, 0);
    }

    bool is_valid_row_col(vector<vector<char>>& board, int row, int col) {
        // 检测同行
        for (int i=0; i<9; i++) {
            if (board[row][i] == board[row][col] && i != col) {
                return false;
            }
        }

        // 检测同列
        for (int i=0; i<9; i++) {
            if (board[i][col] == board[row][col] && i != row) {
                return false;
            }
        }
        return true;
    }

    bool is_valid_block(vector<vector<char>>& board, int row, int col) {
        // 同一个block的起始列，起始行
        int start_row = (row / 3) * 3;
        int end_row = start_row + 2;
        int start_col = (col / 3) * 3;
        int end_col = start_col + 2;
        for (int i=start_row; i<end_row; i++) {
            for (int j=start_col; j<end_col; j++) {
                if (board[i][j] == board[row][col] && !(i==row && j==col)) {
                        return false;
                }
            }
        }
       
        return true;
    }

    bool is_valid(vector<vector<char>>& board, int row, int col) {
        return is_valid_block(board, row, col) && is_valid_row_col(board, row, col);
    }
    
    bool is_origin_filled(int row, int col) {
        if (origin_board[row][col] == '.') {
            return true;
        } 
        return false;
    }

    void back_trace(vector<vector<char>>& board, int idx) {

        if (idx > 80) {
            return ;
        }

        int row = idx/9;
        int col = idx%9;

        // 如果是填过数的，跳过
        if (is_origin_filled(row, col)) {
            back_trace(board, idx+1);
        } else {
            for (auto candidate : candidates) {
                board[row][col] = candidate;
                if (is_valid(board, row, col)) {
                    back_trace(board, idx+1);
                }
            }
        }
    }
};
