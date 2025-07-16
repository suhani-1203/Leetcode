class Solution {
public:
    int dfs(int node, vector<vector<int>> &adj,
            vector<int>& visNode,
            vector<int>& timeInPath,
            int currTime,
            int& maxCycleLen) {
        
        visNode[node] = 1;
        timeInPath[node] = currTime;
        
        for (auto it : adj[node]) {
            if (!visNode[it]) {
                dfs(it, adj, visNode, timeInPath, currTime + 1, maxCycleLen);
            }
            else if (timeInPath[it] != -1) {
                // Found a back edge → compute cycle length
                int cycleLen = currTime - timeInPath[it] + 1;
                maxCycleLen = max(maxCycleLen, cycleLen);
            }
        }
        
        timeInPath[node] = -1; // backtrack
        return maxCycleLen;
    }
    
    int longestCycle(vector<int>& edges) {
        int V = edges.size();
        
        vector<vector<int>> adj(V);
        for (int u = 0; u < V; u++) {
            int v = edges[u];
            if (v != -1) {
                adj[u].push_back(v);
            }
        }

        vector<int> visNode(V, 0);
        vector<int> timeInPath(V, -1);
        int maxCycleLen = -1;
        
        for (int i = 0; i < V; i++) {
            if (!visNode[i]) {
                dfs(i, adj, visNode, timeInPath, 0, maxCycleLen);
            }
        }
        
        return maxCycleLen;
    }
};
