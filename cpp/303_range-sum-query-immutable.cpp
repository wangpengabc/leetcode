// https://leetcode.cn/problems/range-sum-query-immutable/
// 前缀数组和

class NumArray {
public:
    vector<int> pre_sum;
    NumArray(vector<int>& nums) {
        int sum = 0;
        pre_sum.push_back(sum);
        for (auto num : nums) {
            sum += num; 
            pre_sum.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        return pre_sum[right+1] - pre_sum[left]; 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
