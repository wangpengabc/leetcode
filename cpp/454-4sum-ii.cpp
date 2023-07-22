// https://leetcode.cn/problems/4sum-ii/
// 哈希表，空间换时间

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sum_nums12, sum_nums34;

        for (int num1 : nums1) {
            for (int num2 : nums2) {
                sum_nums12[num1 + num2]++;
            }
        }

        for (int num3 : nums3) {
            for (int num4 : nums4) {
                sum_nums34[num3 + num4]++;
            }
        }

        int num_matched_pair = 0;

        for ( auto const& [sum_num12, cnt_sum_num12] : sum_nums12 ) {
            int target_num = 0-sum_num12;
            if ( sum_nums34.count(target_num) ) {
                num_matched_pair += sum_nums34[-sum_num12] * cnt_sum_num12;
            }
        }
        return num_matched_pair;
    }
};
