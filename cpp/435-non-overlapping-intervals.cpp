// https://leetcode.cn/problems/non-overlapping-intervals/description/
// 贪心算法，每次都选结束时间最早的区间（可是为什么这个就是最优的呢）

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& range1, vector<int>& range2){
            return range1[1] < range2[1];
        });

        int cur_end = INT_MIN;
        int non_overlap_num = 0;
        int interval_num = intervals.size();
        for (auto inter_range : intervals) {
            // if begining is larger than last ending
            if (inter_range[0] >= cur_end) {
                non_overlap_num++;
                cur_end = inter_range[1];
            }
        }

        return interval_num - non_overlap_num;
    }
};
