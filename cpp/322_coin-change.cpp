// https://leetcode.cn/problems/coin-change/
// 动态规划

class Solution {
public:
    vector<int> amount_cnt;
    int coinChange(vector<int>& coins, int amount) {
        amount_cnt = vector<int>(amount.size(), )
    }

    int dp(vector<int>& coins, int amount) {

        if (amount < 0) {
            return -1;
        }
        if (amount == 0 ) {
            return 0;
        }

        int min_cnt = INT_MAX;
        for (auto coin : coins) {
            int cnt = coinChange(coins, amount-coin);
            if (cnt == -1) {
                continue;
            }
            min_cnt = min(cnt + 1, min_cnt);
        }
        if (min_cnt == INT_MAX) {
            return -1;
        } 
        return min_cnt;
    }
};
