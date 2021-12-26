class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ret;
        vector<int> path;
        path.push_back(0);
        dfs(graph, 0, (int)(graph.size() - 1), path, ret);
        return ret;
    }
private:
    void dfs(vector<vector<int>> &graph, int source, int dest, vector<int> path, vector<vector<int>> &ans) {
        if (source == dest) {
            ans.push_back(path);
            return;
        }
        for (auto it: graph[source]) {
            path.push_back(it);
            dfs(graph, it, dest, path, ans);
            path.pop_back();
        }
    }
};