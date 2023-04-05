// https://leetcode.cn/circle/discuss/fbhhev/

// https://leetcode.cn/circle/discuss/fbhhev/
// https://blog.csdn.net/K346K346/article/details/126958310
// 小于 n 的最大数

#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

static int n = 222;
static int cur_max = 0;

void back_trace(vector<int>& candidates, int pre_num) {
    if (pre_num > n) {
        return;
    } else {
        if (pre_num > cur_max) {
            cur_max = pre_num;
        }
    }

    vector<bool> is_used(candidates.size(), false);
    int pre_num_last = 0;

    for (int i=0; i<candidates.size(); i++) {
        pre_num_last = pre_num;
        pre_num = pre_num*10 + candidates[i];
        is_used[i] = true;
        back_trace(candidates, pre_num);
        pre_num = pre_num_last;
    }
}


int main() {
    vector<int> candidates_int{1, 2, 9, 4};
    sort(candidates_int.begin(), candidates_int.end(), greater<int>());

    back_trace(candidates_int, 0);

    cout << "candidate: ";
    for (auto candidate : candidates_int) {
        cout << candidate << " ";
    }
    cout << "\n";

    std::cout << "n:" << n << ", max:" << cur_max << endl;

    return 0;
}
