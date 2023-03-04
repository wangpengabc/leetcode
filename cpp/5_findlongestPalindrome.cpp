// https://leetcode.cn/problems/longest-palindromic-substring/
// 找到最长回文串，利用左右指针，从中间开始往左右两边移动

class Solution {
public:
    string findlongestPalindrome(const string& s, int l, int r) {
        while (l>=0 && r<s.length()
                 && s.at(l) == s.at(r)) {
            l--;
            r++;
        }
        if (r == l || r-l == 1) {
            return "";
        }

        return s.substr(l+1, r-l-1);
    }

    string longestPalindrome(string s) {
        string res = "";
        for (int i=0; i<s.length(); i++) {
            string s1 = findlongestPalindrome(s, i, i);
            string s2 = findlongestPalindrome(s, i, i+1);

            res = s1.length() > res.length() ? s1:res;
            res = s2.length() > res.length() ? s2:res;
        }
        return res;
    }
};
