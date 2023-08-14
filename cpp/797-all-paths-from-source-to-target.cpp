// https://leetcode.cn/problems/all-paths-from-source-to-target/description/
// 图遍历， DFS

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        dfs_path(0, graph, res, {0, });
        return res;
    }

    void dfs_path(int cur_node, vector<vector<int>>& graph, vector<vector<int>>& res, vector<int> path) {
        if (cur_node == graph.size()-1) { 
            res.push_back(path); 
            return;
        }

        if (graph[cur_node].size() == 0) {
            return;
        }

        for (auto neighbour_node : graph[cur_node]) {
            path.push_back(neighbour_node);
            dfs_path(neighbour_node, graph, res, path);
            path.pop_back();
        }

    }

};
