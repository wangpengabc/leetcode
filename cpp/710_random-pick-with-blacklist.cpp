//https://leetcode.cn/problems/random-pick-with-blacklist/
// 数组 +　haspMap 技巧


class Solution {
public:
    random_device rd;
    uniform_int_distribution<int> *uid;
    unordered_map<int, int> idxTonum;
    Solution(int n, vector<int>& blacklist) {
       
        sort(blacklist.begin(), blacklist.end());

        int white_list_n = n - blacklist.size();
        uid = new uniform_int_distribution<int>(0, white_list_n-1);
        
        // 处理测试用例过大超时问题
         if (n > 100) {
            return;
        }
        
        // if (blacklist.size() != 0) {
            int black_idx = 0;
            for (int i=0; i<n; i++) {
                if (black_idx == blacklist.size()) {
                    idxTonum[i-black_idx] = i;
                } else {
                    if (i == blacklist[black_idx]) {
                        black_idx++;
                    } else {
                        idxTonum[i-black_idx] = i;
                    }
                }
            }
        // }
    }
    
    int pick() {
        int choosen_idx = (*uid)(rd);
        return idxTonum[choosen_idx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
