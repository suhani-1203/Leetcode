class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> bannedSet;
        for (int x : banned)
            if (x <= n)
                bannedSet.insert(x);

        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (bannedSet.count(i)) continue;
            if (maxSum - i < 0) break;  // allow equality
            maxSum -= i;
            count++;
        }
        return count;
    }
};
