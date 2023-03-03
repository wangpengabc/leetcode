// https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/
// 左右指针

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0, right=numbers.size()-1;
        std::vector<int> idx_v {0, 0};
        int sum;
        while (left < right) {
            sum = numbers[left] + numbers[right];
            if (sum == target) {
                idx_v[0] = left+1;
                idx_v[1] = right+1;
                return idx_v;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return idx_v;
    }
};
