// https://leetcode.cn/problems/minimum-window-substring/


class Solution {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> window , need;
        for (int i; i<t.length(); i++) need[t.at(i)]++;

        string min_window = "";
        int left=0, right=0;
        int valid = 0;

        while ( right < s.length() ) {
            char c_right = s.at(right);
            right++;
            // 对window进行操作
            if (need.count(c_right)) {
                window[c_right]++;
                if (window.count(c_right) == need.count(c_right)) {
                    valid++;
                }
            }

            // 判断是否进行left操作
            while (valid == need.size()) {
                min_window = s.substr(left, right-left);            
                char c_left = s.at(left);
                left++;
                // left 操作
                if (need.count(c_left)) {
                    if (window[c_left] == need[c_left]) {
                        valid--;
                    }
                    window[c_left]--;
                }

            }
            
        }
        return min_window;
    }
};
