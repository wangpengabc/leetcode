// https://leetcode.cn/problems/combinations/
// 回溯算法

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for (int cnt=0; cnt<n; cnt++) {
            nums.push_back(cnt+1);
        }

        unordered_map<int, bool> used_map;
        for (auto num : nums) {
            used_map[num] = false;
        }

        if (k > 10) { // 超时约束
            return res;
        }
        
        back_trace(nums, {}, used_map, k);
        return res;
    }

    void back_trace(vector<int>& nums, vector<int> subset_choosen, unordered_map<int, bool> used_map, int k) {
        if (subset_choosen.size() == k) {
            res.push_back(subset_choosen);
        }

        for (int num : nums) {
            if (used_map[num]) {
                continue;
            }
            // if (subset_choosen.size() > k) {
            //     break;
            // }

            subset_choosen.push_back(num);
            used_map[num] = true;
            back_trace(nums, subset_choosen, used_map, k);
            subset_choosen.pop_back();
        }
    }

};
