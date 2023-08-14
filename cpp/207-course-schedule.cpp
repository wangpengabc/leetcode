// https://leetcode.cn/problems/course-schedule/description/
// DFS + 图遍历， 注意onPath数组的使用，和visited有区别。
// 类比贪吃蛇游戏，visited 记录蛇经过过的格子，而 onPath 仅仅记录蛇身。onPath 用于判断是否成环，类比当贪吃蛇自己咬到自己（成环）的场景。

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> init = {};
        vector<vector<int>> graph(numCourses, init);
        for (auto dep : prerequisites) {
            graph[dep[0]].push_back(dep[1]);
        }
        // for (auto graph_nodes : graph) {
        //     // cout << "deps: ";
        //     for (auto node : graph_nodes) {
        //         cout << " " << node;
        //     }
        //     cout << endl;
        // }

        for (int i=0; i<numCourses; i++) {
            if (graph[i].size() != 0) {
                cout << "i: " << i << endl;
                vector<bool> visitied(numCourses, false);
                vector<bool> onPath(numCourses, false);
                bool is_loop = false;
                dfs_loop(graph, i, visitied, onPath, is_loop);
                if (is_loop) {
                    return false;
                }
            }
        }
        return true;
    }

    void dfs_loop(vector<vector<int>>& graph, int cur_node, vector<bool>& visitied, vector<bool>& onPath, bool& is_loop) {
        if (onPath[cur_node] == true) {
            is_loop = true;
            return ;
        }

        if (graph[cur_node].size() == 0) {
            return ;
        }

        if (visitied[cur_node] == true) {
            return;
        }

        // cout << "dfs cur_node: " << cur_node << endl;

        visitied[cur_node] = true;
        onPath[cur_node] = true;
        for (int neighbour : graph[cur_node]) {
            // cout << "dfs neighbour: " << neighbour << endl;
            dfs_loop(graph, neighbour, visitied, onPath, is_loop);
        }
        onPath[cur_node] = false;

    }
};
