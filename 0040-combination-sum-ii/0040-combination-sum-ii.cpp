class Solution {
public:
    void generateCombinations(int index, vector<int> &candidates, int target, vector<int> &current, vector<vector<int>> &ans) {
    // Base case: if the target is reached
    if (target == 0) {
        ans.push_back(current);
        return;
    }

    for (int i = index; i < candidates.size(); ++i) {
        // Skip duplicates in the candidates list
        if (i > index && candidates[i] == candidates[i - 1]) {
            continue;
        }

        // Stop if the candidate exceeds the target
        if (candidates[i] > target) {
            break;
        }

        // Include the current candidate
        current.push_back(candidates[i]);

        // Recurse with reduced target and move to the next candidate
        generateCombinations(i + 1, candidates, target - candidates[i], current, ans);

        // Backtrack
        current.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> current;

    // Sort candidates to handle duplicates easily
    sort(candidates.begin(), candidates.end());

    // Generate combinations
    generateCombinations(0, candidates, target, current, ans);

    return ans;
    }
};