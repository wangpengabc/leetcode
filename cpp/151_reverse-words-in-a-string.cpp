// https://leetcode.cn/problems/reverse-words-in-a-string/
// 数组的操作技巧

class Solution {
public:
    string reverseWords(string s) {
        // reverse char-by-char
        reverse(s.begin(), s.end());

        // for_each(s.begin(), s.end(), [](char in) { cout << in;});
        // cout<<endl;

        // reverse by word
        decltype(s.begin()) it_pre = s.begin();
        for (auto it_begin=s.begin(); it_begin<s.end(); ++it_begin) {
            if(*it_begin == ' ' ) {
                reverse(it_pre, it_begin);
                it_pre = it_begin+1;
            } 

            if (it_begin==(s.end()-1)) {
                reverse(it_pre, it_begin+1);
                it_pre = it_begin;
            }
        }

        while (*(s.begin()) == ' ') {
            s = s.substr(1, s.size());
        }

        while (*(s.end()-1) == ' ') {
            s = s.substr(0, s.size()-1);
        }

       s = regex_replace(s,
                        std::regex("[\\s]+"),
                        " ");

        return s;
    }

};
