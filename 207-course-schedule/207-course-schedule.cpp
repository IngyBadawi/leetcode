class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<bool> vis(numCourses);
        vector<int> inDegree(numCourses);
        
        for (int i = 0 ; i < prerequisites.size() ; i++) {
            int subj = prerequisites[i][0];
            int prerequisite = prerequisites[i][1];
            inDegree[subj]++;
            adj[prerequisite].push_back(subj);
        }
        
        for (int i = 0 ; i < numCourses ; i++) {
            if (inDegree[i] == 0 && !vis[i]) {
                vis[i] = true;
                dfs(i, vis, inDegree, adj);
            }
        }
        
        for (int i = 0 ; i < numCourses ; i++) {
            if (!vis[i])
                return false;
        }
        
        return true;
        
    }
    
private:
    void dfs(int u, vector<bool> &vis, vector<int> &inDegree, vector<vector<int>> &adj) {
        for (int i = 0 ; i < adj[u].size() ; i++) {
            inDegree[adj[u][i]]--;
            if (inDegree[adj[u][i]] == 0 && !vis[adj[u][i]]) {
                vis[adj[u][i]] = true;
                dfs(adj[u][i], vis, inDegree, adj);
            }
        }
    }
};