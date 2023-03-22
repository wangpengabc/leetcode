// https://leetcode.cn/problems/combination-sum-iii/
// 回溯算法， 剪枝

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<bool> is_used(10, false); // The first position is ignored.

        back_trace(k, n, {}, is_used);
        return res;
    }

    void back_trace(int k, int target, vector<int> subset_prefix, vector<bool> is_used) {

        for (int i=1; i<10; i++) {
            if (is_used[i]) {
                continue;
            }


            is_used[i] = true;
            subset_prefix.push_back(i);
            int sum = accumulate(subset_prefix.begin(), subset_prefix.end(), 0);
            if (sum == target && subset_prefix.size() == k) {
                res.push_back(subset_prefix);
            }
            if (sum > target) {
                break;
            }
            back_trace(k, target, subset_prefix, is_used);
            subset_prefix.pop_back();

        }
    }

};
