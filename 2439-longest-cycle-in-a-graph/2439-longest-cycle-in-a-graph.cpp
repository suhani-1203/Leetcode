class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n, -1);
        int maxCycle = -1;
        int time = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] != -1)
                continue;

            int curr = i;
            unordered_map<int, int> pathTime;

            while (curr != -1) {
                if (visited[curr] != -1) {
                    // Found a previously visited node
                    if (pathTime.count(curr)) {
                        int cycleLen = time - pathTime[curr];
                        maxCycle = max(maxCycle, cycleLen);
                    }
                    break;
                }

                visited[curr] = time;
                pathTime[curr] = time;
                time++;
                curr = edges[curr];
            }
        }

        return maxCycle;
    }
};

