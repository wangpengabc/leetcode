// https://leetcode.cn/problems/find-all-anagrams-in-a-string/
// 滑动窗口
// 子字符串问题

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        std::unordered_map<char, int> window, need;
        for (int i=0; i<p.length(); i++) need[p[i]]++;

        int left = 0, right = 0;
        int valid = 0;
        vector<int> valid_index{};
        
        while (right < s.length()) {
            // expand right
            char right_c = s[right];
            right++;
            if (need.count(right_c)) {
                window[right_c]++;
                if (window[right_c] == need[right_c]) {
                    valid++;
                }
            }

            // shrink left
            while (valid == need.size()) {
                if ((right-left) == p.length()) {
                    // valid_index.insert(valid_index.end(), left);
                    valid_index.push_back(left);
                }
                char left_c = s[left];
                left++;
                if (need.count(left_c)) {
                    if (window[left_c] == need[left_c]) {
                        valid--;
                    }
                    window[left_c]--;
                }
            }
        }
        return valid_index;
    }
};
