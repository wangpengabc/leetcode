// https://leetcode.cn/problems/koko-eating-bananas/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // 二分法， 自变量为吃香蕉的速度，输出为消耗的时间，target为满足约束时间的最小速度
        vector<int> speed_candidates;
        int total_bananas = 0; 
        for_each(piles.begin(), piles.end(), [&](int pile_weight){ total_bananas += pile_weight; });
        // cout << "total_bananas: " << total_bananas << endl;
        for (int i=ceil(total_bananas/h); i<total_bananas; i++) {
            speed_candidates.push_back(i);
        }

        int left = 0;
        int right = speed_candidates.size() - 1;
        while (left <= right) {
            int mid = (left+right)/2;
            int time = get_time(piles, speed_candidates[mid]);
            // cout << "------------------------"<< endl;
            // cout << "left: " << left << " right: " << right << endl;
            // cout << "mid_speed: " << speed_candidates[mid] << " time: " << time << endl;

            if (time < h) {
                right = mid - 1;
            } else if (time > h) {
                left = mid + 1;
            } else if (time == h) {
                right = mid - 1;
            }
        }
        return speed_candidates[left];
    }

    int get_time(vector<int>& piles, int k) {
        int time = 0;
        for (auto num : piles) {
            // cout << )num/k << " ";
            time += num / k + (num%k ==0 ? 0 : 1);
        }
        // cout << endl;
        return time;
    }
};

// class Solution {
//   public:
//     int time(vector<int>& piles, int speed) {
//         int ret = 0;
//         for (int pile : piles) {
//             ret += (pile / speed);
//             if (pile % speed != 0) {
//                 ++ret;
//             }
//         }
//         return ret;
//     }

//     int minEatingSpeed(vector<int>& piles, int h) {
//         int left = 1, right = (int)1e9 + 1;
//         while (left < right) {
//             int speed = left + (right - left) / 2;
//             if (time(piles, speed) <= h) {
//                 right = speed;
//             } else {
//                 left = speed + 1;
//             }
//         }
//         return right;
//     }
// };
