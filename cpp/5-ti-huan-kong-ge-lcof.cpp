// https://leetcode.cn/problems/ti-huan-kong-ge-lcof/
// 待提升为 双指针版本

class Solution {
public:
    string replaceSpace(string s) {
        int len_s = s.size();
        string insert_str = "%20";
        vector<int> space_poses;
        int pos_idx = len_s-1;

        while (pos_idx >= 0) {
            if (s.at(pos_idx) == ' ') {
                space_poses.push_back(pos_idx);
                s[pos_idx] = '%';
            }
            pos_idx--;
        }
        for (auto space_pos : space_poses) {
            s.insert(space_pos+1, "20");
        }
        return s;
        
    }
};
