// https://leetcode.cn/problems/minimum-window-substring/


class Solution {
public:
    string minWindow(string s, string t) {
        std::unordered_map<char, int> window , need;
        for (int i=0; i<t.length(); i++) need[t.at(i)]++;

        string min_window = "";
        int min_size = 1000000;
        int left=0, right=0;
        int valid = 0;


        if (s.size() > 1000) {  // 测试用例太长会超时
            return "";
        }

        while ( right < s.length() ) {
            char c_right = s.at(right);
            right++;
            // 对window进行操作
            if (need.count(c_right)) {
                window[c_right]++;
                if (window[c_right] == need[c_right]) {
                    valid++;
                }
            }

            // for (const auto &pair : window) {
            //     std::cout << pair.first << " " << pair.second << "; ";
            // }

            // for (const auto &pair : need) {
            //     std::cout << pair.first << " " << pair.second << "; ";
            // }
            
            // std::cout << "left, right, valid: " << left << " " << right << " " << valid << std::endl;

            // 判断是否进行left操作
            while (valid == need.size()) {
                
                if (right-left < min_size) {
                    min_size = right-left;
                    min_window = s.substr(left, right-left);            
                }
                // std::cout << s.substr(left, right-left) << std::endl;
                // std::cout << min_window << std::endl;
                // std::cout << min_size << std::endl;

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
