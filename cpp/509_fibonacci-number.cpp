// https://leetcode.cn/problems/fibonacci-number/
// 动态规划

class Solution {
public:
    int fib(int n) {
        static map<int, int> dp_table;
        if (n == 0 || n == 1) {
            return n;
        }
        if (dp_table.count(n)) {
            return dp_table[n];
        }

        int res = fib(n-1) + fib(n-2);
        
        if (dp_table.count(n) == 0) {
            dp_table[n] = res;
        }

        return res;
    }
};
