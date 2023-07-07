// https://leetcode.cn/problems/minimum-size-subarray-sum/
// 滑动窗口

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_series_num = INT_MAX, series_cnt = 0;
        int left = 0, right = 0;
        int sum_window = 0;

        while ( right < nums.size() ) {
            sum_window += nums[right];
            right++;
            while ( sum_window >= target ) {
                series_cnt = right - left;
                if ( series_cnt < min_series_num ) {
                    min_series_num = series_cnt;
                }
                sum_window -= nums[left];
                left++;
            }
        }

        if ( min_series_num == INT_MAX ) {
            return 0;
        } else {
            return min_series_num;
        }
    }
};
