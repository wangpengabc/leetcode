//https://leetcode.cn/problems/remove-duplicate-letters/
// 单调栈 + 特殊的数据结构；核心在于决定何时入栈、出栈，从而决定最终哪些字符保存在栈中作为最终结果
class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> stk;
        int count[256] = {0};
        
        for (auto c : s) {
            count[c]++;
        }

        bool inStack[256] = {false};
        
        for (auto c : s) {
            count[c]--;
            if (inStack[c]) {
                continue;
            } 

            while (!stk.empty() && stk.top() > c ) {
                if (count[stk.top()] == 0) {
                    break;
                }
                inStack[stk.top()]  = false;
                stk.pop();
            }

            inStack[c] = true;
            stk.push(c);
        }

        string res;
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;


    }
};
