// https://leetcode.cn/problems/valid-anagram/
// 哈希表

class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_char_cnt[26] = {0};
        int t_char_cnt[26] = {0};


        for ( int i=0; i<s.size(); i++ ) {
            s_char_cnt[s.at(i) - 'a']++;
        }

        for ( int i=0; i<t.size(); i++ ) {
            t_char_cnt[t.at(i) - 'a']++;
        }

        for ( int i=0; i<26; i++ ) {
            if ( s_char_cnt[i] != t_char_cnt[i] ) {
                return false;
            }
        }
        return true;

    }
};
