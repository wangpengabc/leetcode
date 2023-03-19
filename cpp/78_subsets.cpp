// https://leetcode.cn/problems/subsets/
// 回溯算法

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        unordered_map<int, bool> used_map;
        for (auto num : nums) {
            used_map[num] = false;
        }
        
        back_trace(nums, {}, used_map);
        return res;
    }

    void back_trace(vector<int>& nums, vector<int> subset_choosen, unordered_map<int, bool> used_map) {
        res.push_back(subset_choosen);

        for (int num : nums) {
            if (used_map[num]) {
                continue;
            }

            subset_choosen.push_back(num);
            used_map[num] = true;
            back_trace(nums, subset_choosen, used_map);
            subset_choosen.pop_back();
        }
    }

};
