// https://leetcode.cn/problems/permutations/
// 回溯算法
// 三要素： 停止条件，候选项，已选择路径

class Solution {
private:
    vector<vector<int>> res;
    int target_size = 0;
    vector<vector<int>> permute_(vector<int>& nums) {
        target_size = nums.size();
        back_trace(nums, {});
        return res;
    }

    void back_trace(vector<int> candidates, vector<int> trace) {
        if (trace.size() == target_size) {
            res.push_back(trace);
        }

        int idx = 0;
        
        for (auto choice : candidates) {
            trace.push_back(choice);
            candidates.erase(candidates.begin()+idx);
            back_trace(candidates, trace);
            candidates.insert(candidates.begin()+idx, choice);
            trace.pop_back();
            idx++;
        }
    }



public:
    vector<vector<int>> permute(vector<int>& nums) {
        return permute_(nums);
    }
};
