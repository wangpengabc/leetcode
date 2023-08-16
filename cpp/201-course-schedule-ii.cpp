// https://leetcode.cn/problems/course-schedule-ii/description/
// 图的环检测 + 拓扑排序， DFS + 后序遍历，输出结果就是拓扑排序结果。

class Solution {
public:
    vector<int>* graph;
    vector<bool> is_visited;
    vector<bool> on_path;
    vector<int> post_order;
    bool is_loop;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        isLoop(numCourses, prerequisites);

        if (is_loop) {
            return {};
        } else {
            reverse(post_order.begin(), post_order.end());
            vector<int> res(numCourses);
            for (int i = 0; i < numCourses; i++) {
                res[i] = post_order[i];
            }
            return res;
        }
    }

    void isLoop(int numCourses, vector<vector<int>>& prerequisites) {
        graph = new vector<int>[numCourses];

        for (auto prerequis : prerequisites) {
            int cur = prerequis[1];
            int dep = prerequis[0];
            graph[cur].push_back(dep);
        }

        is_visited.resize(numCourses);
        on_path.resize(numCourses);

        for (int i=0; i<numCourses; i++) {
            dfsLoop(i);
        }

    }

    void dfsLoop(int cur_node) {
        if (is_visited[cur_node]) {
            return ;
        }
        if (is_loop) {
            return ;
        }
        if (on_path[cur_node]) {
            return ;
        }

        is_visited[cur_node] = true;
        on_path[cur_node] = true;
        for (auto neigh : graph[cur_node]) {
            if (on_path[neigh]) {
                is_loop = true;
            }
            dfsLoop(neigh);
        }

        post_order.push_back(cur_node);
        on_path[cur_node] = false;

    }
};
