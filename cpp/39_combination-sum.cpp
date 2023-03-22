// https://leetcode.cn/problems/combination-sum/
// 回溯

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        unordered_map<int, bool> is_used;
        for (auto candidate : candidates) {
            is_used[candidate] = false;
        }

        back_trace(candidates, target, {}, is_used);
        return res;
    }

    void back_trace(vector<int>& candidates, int target, vector<int> subset_prefix, unordered_map<int, bool> is_used) {

        for (auto candidate : candidates) {
            if (is_used[candidate]) {
                continue;
            }
            
            subset_prefix.push_back(candidate);
            int sum = accumulate(subset_prefix.begin(), subset_prefix.end(), 0);
            if (sum == target) {
                res.push_back(subset_prefix);
            }

            if (sum > target) {
                continue;
            }

            back_trace(candidates, target, subset_prefix, is_used);
            subset_prefix.pop_back();
            is_used[candidate] = true;

        }

    }
};
