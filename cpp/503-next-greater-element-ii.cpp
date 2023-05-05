// https://leetcode.cn/problems/next-greater-element-ii/
// 单调栈技巧+环形数组队尾拷贝技巧

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> new_nums(nums);
        new_nums.insert(new_nums.end(), nums.begin(), nums.end());
        // for_each(new_nums.begin(), new_nums.end(), [](int num){ cout << num << " ";});

        vector<int> next_max;
        stack<int> stack_max;
        for (int i=new_nums.size()-1; i>=0; i--) {
            int current_num = new_nums[i];
            while (!stack_max.empty() && current_num >= stack_max.top()) {
                stack_max.pop();
            }

            if (i < nums.size()) {
                if (stack_max.empty()) {
                    next_max.push_back(-1);
                } else {
                    next_max.push_back(stack_max.top());
                }
                // else if (stack_max.top() > current_num){
                //     next_max.push_back(stack_max.top());
                // }
            }
            
            stack_max.push(current_num);
            // cout << stack_max.top();
        }
        reverse(next_max.begin(), next_max.end());
        return next_max;
    }
};
