// https://leetcode.cn/problems/reverse-string/
// 左右指针技巧

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left=0, right=s.size()-1;
        while (left < right) {
            char tmp;
            tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }
};
