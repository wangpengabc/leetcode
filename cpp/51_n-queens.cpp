// https://leetcode.cn/problems/n-queens/
// 回溯算法， 核心在于构造已选择路径+候选空间
// 仍待优化 -> 调用isvalid可以放在从候选空间做出选择的位置，提前剪枝 

class Solution {
public:
    vector<string> plat;
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {

        plat = vector<string>(n, string(n, '.'));
        
        // 待优化， 当n过大时，OJ系统会提示超时
        if (n > 7) {
            return res;
        }

        back_trace(0, n);
        return res;
    }

    void back_trace(int start_row, int n) {
        if (start_row == n) {
            if (is_valid(n)) {
                res.push_back(plat);
            }
            return;
        }

        for (int i=0; i<n; i++) {
            // if (!is_valid(start_row, i, n)) {
            //     continue;
            // }
            // 选择col
            plat[start_row][i] = 'Q';
            // 进入下一个row
            back_trace(start_row+1, n);
            // 取消选择 col
            plat[start_row][i] = '.';
        }
    }

    bool is_valid(int n) {
        // // 检测列
        // for (int i=0; i<n; i++) {
        //     if (plat[i][col] == 'Q') {
        //         return false;
        //     }
        // }
        // // 检测

        // 检测列
        for (int col=0; col<n; col++) {
            int cnt = 0;
            for (int row=0; row<n; row++) {
                if (plat[row].at(col) == 'Q') {
                    cnt++;
                }
            }
            if (cnt > 1) {
                return false;
            }
        }

        // 检测左上到右下对角 ; 左上侧（包括中间），从右上往左下扫描对角线
        for (int col=1; col<n; col++) {
            int i = 0;
            int j = col;
            int cnt = 0;
            while (j >= 0) {
                if (plat[i].at(j) == 'Q') {
                    cnt++;
                }
                if (cnt > 1) {
                    return false;
                }
                j--;
                i++;
            }
        }

       
        // 检测左上到右下对角 ; 右下侧（不包括中间）,从左下向右上扫描对角线
        for (int col=1; col<n; col++) {
            int i = n-1;
            int j = col;
            int cnt = 0;
            while (j < n) {
                if (plat[i].at(j) == 'Q') {
                    cnt++;
                }
                if (cnt > 1) {
                    return false;
                }
                j++;
                i--;
            }
        }

        /*** 右上到左下 ***/
        // 检测右上到左下对角 ; 右上侧（包括中间），从左上往右下扫描对角线
        for (int col=n-1; col>=0; col--) {
            int i = 0;
            int j = col;
            int cnt = 0;
            while (j < n) {
                if (plat[i].at(j) == 'Q') {
                    cnt++;
                }
                if (cnt > 1) {
                    return false;
                }
                j++;
                i++;
            }
        }

        // 检测右上到左下对角  ; 左下侧（不包括中间）,从右下往左上扫描对角线
        for (int col=n-1; col>=0; col--) {
            int i = n-1;
            int j = col;
            int cnt = 0;
            while (j >= 0) {
                if (plat[i].at(j) == 'Q') {
                    cnt++;
                }
                if (cnt > 1) {
                    return false;
                }
                j--;
                i--;
            }
        }
        return true;
    }

};
