// https://leetcode.cn/problems/capacity-to-ship-packages-within-d-days/
// 二分法变种

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // 满足 f(x), x, target 的思路，其中f(x)为以x为自变量的单调变化函数
        // 那么就可以利用二分法
        // 本题中，x表示船的运载能力，f(x)表示运载天数，target表示满足天数情况下的最低运载能力。

        vector<int> search_space;
        int total_weight = 0;
        int max_weight = 0;
        for (auto weight : weights) {
            if (weight > max_weight) {
                max_weight = weight;
            }
            total_weight += weight;
        }
        
        for (int i=max_weight; i<=total_weight; i++) {
            search_space.push_back(i);
        }
        int left = 0;
        int right = search_space.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int time = get_time(weights, search_space[mid]);
            // cout << "mid: " << mid << " left: " << left << " right: " << right << endl;
            // cout << "weight: " << search_space[mid] << " time: " << time << endl;
            if (time < days) {
                right = mid-1;
            } else if (time > days) {
                left = mid+1;
            } else if (time == days) {
                right = mid-1;
            }
        }
        return search_space[left];
    }

    int get_time(vector<int>& weights, int caplity) {
        int days_cnt = 0;
        int weight_sum = 0;
        for (auto weight : weights) {
            if (weight_sum + weight < caplity) {
                weight_sum += weight;
            } else if (weight_sum + weight > caplity) {
                weight_sum = weight;
                days_cnt++;
            } else if (weight_sum + weight == caplity) {
                weight_sum = 0;
                days_cnt++;
            }
        }
        if (weight_sum > 0) {
            days_cnt++;
        }
        return days_cnt;
    }
};
