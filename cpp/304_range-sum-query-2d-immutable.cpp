// https://leetcode.cn/problems/range-sum-query-2d-immutable/
// 前缀数组

class NumMatrix {
public:
    vector<vector<int>> pre_sum;
    NumMatrix(vector<vector<int>>& matrix) {
        int num_row = matrix.size();
        int num_col = (matrix[0]).size();
        for (int row=0; row<=num_row; row++) {
            vector<int> pre_sum_row;
            for (int col=0; col<=num_col; col++) {
                // get the pre sum
                int sum = 0; 
                for (int i=0; i<row; i++) {
                    for (int j=0; j<col; j++) {
                        sum += matrix[i][j];
                    }
                }
                pre_sum_row.push_back(sum);
            }
            pre_sum.push_back(pre_sum_row);
        }
        // for (auto pre_sum_row : pre_sum) {
        //     for (auto item : pre_sum_row) {
        //         cout << item << " ";
        //     }
        //     cout << "\n";
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pre_sum[row2+1][col2+1] - pre_sum[row1][col2+1] - pre_sum[row2+1][col1] + pre_sum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
