// https://leetcode.cn/problems/sudoku-solver/

class Solution {
public:
    using Pos = vector<int>;
    using Canadidate = vector<char>;
    vector<pair<Pos, Canadidate>> construct_candidates(vector<vector<char>>& board) {
        
    }

    void solveSudoku(vector<vector<char>>& board) {
        // 首先统计需要填入的空白格个数，然后构造对应长度的vector, 
        // vector的element也是vector,用于存储该空白格的可选候选值
        auto candidates = construct_candidates(board);

    }
};
