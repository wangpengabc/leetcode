// https://leetcode.cn/problems/sudoku-solver/
// 回溯算法

class Solution {
public:
    // using Pos = vector<int>;
    // using Canadidate = vector<char>;
    // vector<pair<Pos, Canadidate>> construct_candidates(vector<vector<char>>& board) {
    //     vector<pair<Pos, Canadidate>> candidates;

    //     return candidates;
    // }


    vector<vector<char>> origin_board;
    vector<vector<char>> success_board;
    vector<char> candidates{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    bool sucess_flag = false;
    void solveSudoku(vector<vector<char>>& board) {
        origin_board = board;
        back_trace(board, 0);
        board = success_board;
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
        // cout << "origin : ------------- \n";
        // print(origin_board);
        // cout << "origin end ------------- \n";

        if (origin_board[row][col] == '.') {
            return false;
        }
        return true;
    }

    void back_trace(vector<vector<char>>& board, int idx) {
        // cin.ignore();
        if (sucess_flag) {
            return;
        }
        // cout << "idx: " << idx << endl;
        if (idx > 80) {
            int row_pre = (idx-1)/9;
            int col_pre = (idx-1)%9;
            if (is_valid(board, row_pre, col_pre)) {
                sucess_flag = true;
                success_board = board;
            }
            return ;
        }

        if (idx > 0) {
            int row_pre = (idx-1)/9;
            int col_pre = (idx-1)%9;

            if (!is_valid(board, row_pre, col_pre)) {
                return ;
            }
        }

        int row = idx/9;
        int col = idx%9;

        // 如果是填过数的，跳过
        if (is_origin_filled(row, col)) {
            // cout << "filled\n";
            back_trace(board, idx+1);
        } else {
            for (auto candidate : candidates) {
                if (sucess_flag) {
                    return ;
                }
                board[row][col] = candidate;
                // cout << "valid" << "idx:" << idx << "row: " << row << "col: " << col << endl;
                // print(board);
                back_trace(board, idx+1);
                board[row][col] = '.';
                // board[row][col] = '.';
            }
        }
    }
};
