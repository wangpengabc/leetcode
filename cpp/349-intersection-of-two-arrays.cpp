// https://leetcode.cn/problems/intersection-of-two-arrays/
// 手动实现哈希表
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> cnt(1000, 0);
        for (auto num : nums1) {
            cnt[num]++;
        }

        vector<int> cnt1(1000, 0);
        vector<int> unique_nums;
        for (auto num : nums2) {
            cnt1[num]++;
            if (cnt[num] > 0 && cnt1[num]==1) {
                unique_nums.push_back(num);
            }
        }

        return unique_nums;
    }
};
