class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<bool> vis(numCourses);
        vector<int> inDegree(numCourses);
        vector<int> order;
        
        for (int i = 0 ; i < prerequisites.size() ; i++) {
            int subj = prerequisites[i][0];
            int prerequisite = prerequisites[i][1];
            inDegree[subj]++;
            adj[prerequisite].push_back(subj);
        }
        
        for (int i = 0 ; i < numCourses ; i++) {
            if (inDegree[i] == 0 && !vis[i]) {
                vis[i] = true;
                order.push_back(i);
                dfs(i, vis, inDegree, order, adj);
            }
        }
        
        for (int i = 0 ; i < numCourses ; i++) {
            if (!vis[i])
                return {};
        }
        
        return order;
    }
    
private:
    void dfs(int u, vector<bool> &vis, vector<int> &inDegree, vector<int> &order, vector<vector<int>> &adj) {
        for (int i = 0 ; i < adj[u].size() ; i++) {
            inDegree[adj[u][i]]--;
            if (inDegree[adj[u][i]] == 0 && !vis[adj[u][i]]) {
                vis[adj[u][i]] = true;
                order.push_back(adj[u][i]);
                dfs(adj[u][i], vis, inDegree, order, adj);
            }
        }
    }
};