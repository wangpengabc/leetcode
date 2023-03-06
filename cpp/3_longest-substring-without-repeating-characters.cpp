// https://leetcode.cn/problems/longest-substring-without-repeating-characters/
// 滑动窗口问题

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> window;
        int left=0, right=0;
        int max_len = 0;

        while (right < s.length()) {
            // 操作右侧指针
            char right_c = s[right];

            window[right_c]++;
            right++;

            // 操作左侧指针
            while (window[right_c] >= 2) {
                char left_c = s[left];
                window[left_c]--;
                left++;
            }
            
          // 更新答案
            if (right-left > max_len) {
                max_len = right-left;
            }

        }
        return max_len;
    }
};
