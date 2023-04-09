//https://leetcode.cn/problems/rotate-image/
//数组操作技巧

class Solution {
public:
    void print(vector<vector<int>>& matrix) {
        for (auto matric_row:matrix) {
            for (auto item: matric_row) {
                cout << item << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void rotate(vector<vector<int>>& matrix) {
        // 左上到右下对角线镜像翻转
        // 对角线上的元素不变
        for (int diagonal_idx=1; diagonal_idx<matrix.size(); diagonal_idx++) {
            for (int cnt=0; cnt<matrix.size()-diagonal_idx; cnt++) {
                int row = diagonal_idx+cnt;
                int col = cnt;
                // 交换
                int tmp = matrix[row][col];
                matrix[row][col] = matrix[col][row];
                matrix[col][row] = tmp;
            }
        }
        // print(matrix);

        // 左右镜像翻转
        for (int row=0; row<matrix.size(); row++) {
            for (int col=0; col<(static_cast<int>(matrix.size()/2)); col++) {
                int tmp = matrix[row][col];
                matrix[row][col] = matrix[row][matrix.size() - col - 1];
                matrix[row][matrix.size() - col - 1] = tmp;
            }
        }
        // print(matrix);

    }
};
