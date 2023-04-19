//https://leetcode.cn/problems/advantage-shuffle/
// 参考田忌赛马，而不是采用回溯排列，回溯排列复杂度太高

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        // 降序
        priority_queue<pair<int, int>> pq2;
        for (int idx=0; idx<nums2.size(); idx++) {
            // cout << idx << " " << idx << endl;
            pq2.push({nums2[idx], idx});
        }

        // 升序
        sort(nums1.begin(), nums1.end());
        // for (auto num : nums1) {
        //     cout << num ;
        // }
        // cout << endl;

        priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<pair<int, int>>> pq1;

        int left = 0;
        int right = nums1.size()-1;

        while (!pq2.empty()) {
            auto [num2_item, idx] = pq2.top();
            pq2.pop();
            // cout << num2_item << " " << idx << endl;

            if (num2_item >= nums1[right]) {
                pq1.push({idx, nums1[left]});
                left++;
            } else {
                pq1.push({idx, nums1[right]});
                right--;
            }
        }
        for (;!pq1.empty(); pq1.pop()) {
            auto [idx, item] = pq1.top();
            // cout << item << " " << idx << endl;
            res.push_back(item);
        }
        return res;
    }
};
