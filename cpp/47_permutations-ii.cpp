// https://leetcode.cn/problems/permutations-ii/
// 回溯算法， 提前剪枝

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> is_used(nums.size(), false);
        back_trace(nums, is_used, {});
        return res;
    }

    void back_trace(vector<int>& nums, vector<bool> is_used, vector<int> subset_prefix) {
        unordered_map<int, bool> unique_map;
        // for (auto j : subset_prefix) {
        //     cout << j << " ";
        // }
        // cout << endl;
        if (subset_prefix.size() == nums.size()) {
            res.push_back(subset_prefix);
            return;
        }

        for (int i=0; i<nums.size(); i++) {
            if (is_used[i]) {
                continue;
            }
            int num = nums[i];
            // cout << num << "-" << endl;
            if (unique_map.count(num)) {
                continue;
            }

            subset_prefix.push_back(num);
            is_used[i] = true;
            unique_map[num] = true;
            back_trace(nums, is_used, subset_prefix);
            subset_prefix.pop_back();
            is_used[i] = false;
        }
    }
    
};
