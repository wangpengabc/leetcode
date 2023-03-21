// https://leetcode.cn/problems/subsets-ii/
// 回溯算法
// 将不满足要求的提前剪枝

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<bool> is_used(nums.size(), false);

        res.push_back({});
        back_track(nums, {}, is_used);

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
            res.push_back(subset_prefix);
            back_track(nums, subset_prefix, is_used);
            subset_prefix.pop_back();
        }
    }
};
