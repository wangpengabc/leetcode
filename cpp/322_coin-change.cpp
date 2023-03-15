// https://leetcode.cn/problems/coin-change/
// 动态规划

class Solution {
public:
    vector<int> amount_cnt;
    int coinChange(vector<int>& coins, int amount) {
        amount_cnt = vector<int>(amount+1, -666);

        return dp(coins, amount);
    }

    int dp(vector<int>& coins, int amount) {

        if (amount < 0) {
            return -1;
        }
        if (amount == 0 ) {
            return 0;
        }
        if (amount_cnt[amount] != -666) {
            return amount_cnt[amount];
        }

        int min_cnt = INT_MAX;
        for (auto coin : coins) {
            int cnt = dp(coins, amount-coin);
            if (cnt == -1) {
                continue;
            }
            min_cnt = min(cnt + 1, min_cnt);
        }
        if (min_cnt == INT_MAX) {
            amount_cnt[amount] = -1;  // 关键，注意当前amount不满足要求也要进行记录
            return -1;
        } else {
            amount_cnt[amount] = min_cnt;  
        }

        return min_cnt;
    }
};
