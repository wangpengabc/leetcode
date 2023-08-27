LeetCode
========

# labuladong
## 图算法
https://labuladong.github.io/algo/di-yi-zhan-da78c/shou-ba-sh-03a72/huan-jian--e36de/  拓扑排序 + 环检测， 单向图 拓扑排序的结果为什么是后序遍历结果的倒序？ 因为traver函数中通过is_visited作为base case的限制，在后序位置将节点压入数组时，保证了子节点先被压入。

https://labuladong.github.io/algo/di-yi-zhan-da78c/shou-ba-sh-03a72/er-fen-tu--73400/  二分图判定， 二分图的应用，例如： 利用节点表示演员和电影，演员节点间没有连接，电影节点间也没有连接，那么这就是一个二分图。核心思想：DFS遍历 + 染色
![image](https://github.com/wangpengabc/leetcode/assets/22144608/78d6a378-29e2-4661-bff0-633d42d3bbca)
![image](https://github.com/wangpengabc/leetcode/assets/22144608/699d720f-4b35-4af2-b61d-f333eb2beed8)


## 动态规划
动态规划的整体实现思路： https://mp.weixin.qq.com/s/Cw39C9MY9Wr2JlcvBQZMcA ，  存在三种实现思路，自顶向下（dp函数，例如 最长公共子序列，https://mp.weixin.qq.com/s/ZhPEchewfc03xWv9VP3msg， 当然也可以采用dp数组自底向上的形式）、带备忘录的自顶向下、自底向上（dp数组，例如 最短编辑距离 https://labuladong.github.io/algo/di-er-zhan-a01c6/zi-xu-lie--6bc09/jing-dian--e5f5e/）
![1692237438406](https://github.com/wangpengabc/leetcode/assets/22144608/c6a5cc2f-cfbf-4baf-9d35-99eae3736973)
![1692237459236](https://github.com/wangpengabc/leetcode/assets/22144608/a0f1b980-ca30-45f7-97ff-38f4d8bf0b53)



# 笔试题目

## 寻找和为0的最长子数组（变种题目： 给定n个正整数组成的数组，求平均数正好等于k 的最长连续子数组的长度。 本质就是数组中的每个数减去k，然后寻找和为0的最长子数组）
思路： 利用哈希表存储{前缀数组和，对应的索引位置}， 在构建哈希表的过程中，如果出现前缀数组和相等的情况时，那么对应的两个索引之间的子数组之和为0. （两个子数组的和相等，去除两个子数组相同的前缀数组，剩余的子数组之和肯定为0）。




### LeetCode


| # | Title | Solution | Difficulty |
|---| ----- | -------- | ---------- |
|1946|[Largest Number After Mutating Substring](https://leetcode.com/problems/largest-number-after-mutating-substring/) | [C++](./algorithms/cpp/largestNumberAfterMutatingSubstring/LargestNumberAfterMutatingSubstring.cpp), [Java](./algorithms/java/src/LargestNumberAfterMutatingSubtring/largestNumberAfterMutatingSubstring.java)|Medium|
|1945|[Sum of Digits of String After Convert](https://leetcode.com/problems/sum-of-digits-of-string-after-convert/) | [C++](./algorithms/cpp/leetcode/sumOfDigitsOfStringAfterConvert/SumOfDigitsOfStringAfterConvert.cpp)|Easy|

========
### Resources
POJ(Peking University Online Judge)[http://poj.org/]
