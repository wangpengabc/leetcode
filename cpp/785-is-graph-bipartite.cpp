// https://leetcode.cn/problems/is-graph-bipartite/description/
// 二分图判定， 思想： DFS + 染色冲突判断，

class Solution {
public:
    vector<bool> is_visited;
    vector<bool> color;
    bool not_binaray = false;
    bool isBipartite(vector<vector<int>>& graph) {
        int num_node = graph.size();
        is_visited.resize(num_node);
        for_each(is_visited.begin(), is_visited.end(), [](bool label) { label = false; });
        color.resize(num_node);
        for_each(color.begin(), color.end(), [](bool label) { label = false; });
    

        for (int i=0; i<num_node; i++) {
            traverse(graph, i);
        }

        return !not_binaray;
    }

    void traverse(vector<vector<int>>& graph, int cur_node) {
        if (is_visited[cur_node] == true) {
            return ;
        }

        is_visited[cur_node] = true;
        for (auto neigh_node : graph[cur_node]) {
            // 注意邻居节点如果visit过才能进行染色冲突判断，否则无意义
            if (is_visited[neigh_node]) {
                if (!(color[cur_node] ^ color[neigh_node])) {
                    not_binaray = true;
                } 
            } else {
                if (color[cur_node] == false) {
                    color[neigh_node] = true;
                } else {
                    color[neigh_node] = false;
                }
                traverse(graph, neigh_node);
            }
        }

    }
};
