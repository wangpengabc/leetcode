//https://leetcode.cn/problems/split-array-largest-sum/
// 二分法变种

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        // 二分法，自变量为一个区间内数组和最大值，因变量为划分的区间数，target为满足区间数限制的最小的最大值。
        vector<int> max_candidates;
        int sum_of_nums = 0;
        for_each(nums.begin(), nums.end(), [&](int num){ sum_of_nums += num; });
        
        int left = 0;
        for (auto num : nums) {
            if (num > left) {
                left = num;
            }
        }

        int right = sum_of_nums;

        while (left <= right) {
            int mid = (left + right)/2;
            int sub_array_num = get_sub_array_num(nums, mid);
            if (sub_array_num < k) {
                right = mid - 1;
            } else if (sub_array_num > k) {
                left = mid + 1;
            } else if (sub_array_num == k) {
                right = mid - 1;
            }
        }
        return left;
    }

    int get_sub_array_num(vector<int>& nums, int max) {
        int sub_array_cnt = 0;
        int window_sum = 0;
        for (auto num : nums) {
            if (window_sum + num < max) {
                window_sum += num;
            } else if (window_sum + num > max) {
                sub_array_cnt++;
                window_sum = num;
            } else if (window_sum + num == max) {
                sub_array_cnt++;
                window_sum = 0;
            }
        }

        return window_sum==0 ? sub_array_cnt : sub_array_cnt+1;
    }
};
