// 本题的关键在于快慢指针
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int slow=nums[0], fast=nums[0];
        int unique_k = 0;
        for (int i=0; i<nums.size(); i++) {
            fast = nums[i];
            if (fast != slow) {
                unique_k++;
                slow = fast;
                nums[unique_k] = fast;
            }
        }

        return unique_k+1;
    }
};
