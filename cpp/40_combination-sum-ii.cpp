// https://leetcode.cn/problems/combination-sum-ii/
// 回溯算法， 剪枝

class Solution {
public:
    vector<vector<int>> res;
    int target_;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<bool> is_used(candidates.size(), false);
        target_ = target;

        // res.push_back({});
        back_track(candidates, {}, is_used);

        return res;
    }

    void back_track(vector<int>& nums, vector<int> subset_prefix, vector<bool> is_used) {
        unordered_map<int, bool> unique_map;

        for (int i=0; i<nums.size(); i++) {
            if (is_used[i]) {
                continue;
            }
            is_used[i] = true;

            if (unique_map.count(nums[i])) {
                continue;
            }
            unique_map[nums[i]] = true;

            subset_prefix.push_back(nums[i]);
            if(accumulate(subset_prefix.begin(), subset_prefix.end(), 0) == target_) {
                res.push_back(subset_prefix);
            }
            if (accumulate(subset_prefix.begin(), subset_prefix.end(), 0) < target_) {
                back_track(nums, subset_prefix, is_used);
            }
            subset_prefix.pop_back();
        }
    }
};
