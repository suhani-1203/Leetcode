class Solution {
public:
    void dfs(int node, vector<int>& edges,
             vector<int>& visNode,
             vector<int>& timeInPath,
             int currTime,
             int& maxCycleLen) {

        visNode[node] = 1;
        timeInPath[node] = currTime;

        int it = edges[node];
        if (it != -1) {
            if (!visNode[it]) {
                dfs(it, edges, visNode, timeInPath, currTime + 1, maxCycleLen);
            }
            else if (timeInPath[it] != -1) {
                int cycleLen = currTime - timeInPath[it] + 1;
                maxCycleLen = max(maxCycleLen, cycleLen);
            }
        }

        timeInPath[node] = -1; // backtrack
    }

    int longestCycle(vector<int>& edges) {
        int V = edges.size();

        vector<int> visNode(V, 0);
        vector<int> timeInPath(V, -1);
        int maxCycleLen = -1;

        for (int i = 0; i < V; i++) {
            if (!visNode[i]) {
                dfs(i, edges, visNode, timeInPath, 0, maxCycleLen);
            }
        }

        return maxCycleLen;
    }
};

