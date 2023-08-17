// https://leetcode.cn/problems/partition-equal-subset-sum/
// 最长公共子序列， 动态规划， 动态方程（自顶向下）或dp数组（自底向上）均可  

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len_1 = text1.length(), len_2 = text2.length();
        int dp[len_1+1][len_2+1];
         memset(dp, 0, sizeof(dp));

        vector<int> max_vec(3, 0);

        for (int i=0; i<len_1; i++) {
            dp[i][0] = 0;
        }

        for (int j=0; j<len_2; j++) {
            dp[0][j] = 0;
        }

        for (int i=1; i<=len_1; i++) {
            for (int j=1; j<=len_2; j++) {
                if (text1.at(i-1) == text2.at(j-1)) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    max_vec[0] = dp[i-1][j];
                    max_vec[1] = dp[i][j-1];
                    max_vec[2] = dp[i-1][j-1];
                    dp[i][j] = *max_element(max_vec.begin(), max_vec.end());
                }
            }
        }

        return dp[len_1][len_2];
    }
};
