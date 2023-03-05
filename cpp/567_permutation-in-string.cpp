// https://leetcode.cn/problems/permutation-in-string/
// 滑动窗口技巧
// 子字符串问题

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::unordered_map<char, int> window, need;
        for (int i=0; i<s1.length(); i++) need[s1[i]]++;

        int left = 0, right = 0;
        int valid = 0;
        
        while (right < s2.length()) {
            // expand right
            char right_c = s2[right];
            right++;
            if (need.count(right_c)) {
                window[right_c]++;
                if (window[right_c] == need[right_c]) {
                    valid++;
                }
            }

            // shrink left
            while (valid == need.size()) {
                if ((right-left) == s1.length()) {
                    return true;
                }
                char left_c = s2[left];
                left++;
                if (need.count(left_c)) {
                    if (window[left_c] == need[left_c]) {
                        valid--;
                    }
                    window[left_c]--;
                }
            }
        }
        return false;
    }
};
