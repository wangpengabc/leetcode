// https://leetcode.cn/problems/happy-number/submissions/
// 哈希表 hash set
class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n) {
            if (n >= 10) {
                sum += pow((n%10), 2);
            } else {
                sum += n * n;
            }
            // cout << "inner sum: " << sum << endl;
            n = n / 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> sum_set;
        int sum = n;
        while ( true ) {
            sum = getSum(sum);
            // cout << "n: " << sum << endl;
            
            if (sum == 1) {
                return true;
            }

            if ( sum_set.find(sum) != sum_set.end() ) {
                return false;
            }

            sum_set.insert(sum);
        }

    }
};
