// https://leetcode.cn/problems/repeated-dna-sequences/
// 方法1：直接构建string的hash map
// 方法2：滑动窗口 + rabinKarp算法（将窗口内的字符串用数字编码，从而省去滑动窗口substr消耗的时间）

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        if (s.size() < 10) {
            return vector<string>();
        }

        unordered_map<char, int> code_map = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        unordered_set<int> recorded_hash_int;
        int R = 4;
        int L = 10;
        int window_hash = 0;
        for (int i=0; i<L; i++) {
            window_hash = window_hash * R + code_map[s.at(i)];
        }
        recorded_hash_int.insert(window_hash);

        set<string> repeated_str; 
        int right = L;
        int left = 0;
        while (right < s.size()) {
            int left_num = code_map[s.at(left)];
            int right_num = code_map[s.at(right)];
            window_hash = window_hash - left_num * pow(R, L-1);
            window_hash = window_hash * R + right_num;
            left++;

            if (recorded_hash_int.count(window_hash)) {
                string sub_s = s.substr(left, L); 
                repeated_str.insert(sub_s);
            }
            recorded_hash_int.insert(window_hash);
            right++;
        }
       
        return vector<string>(repeated_str.begin(), repeated_str.end());

    }

    // 方法1： hash string
    // vector<string> findRepeatedDnaSequences(string s) {

    //     if (s.size() < 10) {
    //         return vector<string>();
    //     }

    //     unordered_set<string> substr_set;
    //     set<string> repeated_str; 

    //     for (int i=0; i<=s.size()-10; i++) {
    //         string sub_s = s.substr(i, 10);
    //         if (substr_set.count(sub_s)) {
    //             repeated_str.insert(sub_s);
    //         }
    //         substr_set.insert(sub_s);
    //     }
    //     // vector<string> v_repeated_str;
    //     // for (auto r_s : repeated_str) {
    //     //     v_repeated_str.push_back(r_s);
    //     // }
    //     // // return vector<string>(repeated_str);
    //     // return v_repeated_str;
    //     return vector<string>(repeated_str.begin(), repeated_str.end());

    // }
};
