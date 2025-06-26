/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // To store nodes as (col, row, val)
        vector<tuple<int, int, int>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q; // node, (row, col)
        
        if (root == NULL) return {};

        q.push({root, {0, 0}});
        
        while (!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();
            int row = pos.first;
            int col = pos.second;

            nodes.push_back({col, row, node->val});
            
            if (node->left) q.push({node->left, {row + 1, col - 1}});
            if (node->right) q.push({node->right, {row + 1, col + 1}});
        }

        // Sort based on col, then row, then value
        sort(nodes.begin(), nodes.end());

        // Group by column
        map<int, vector<int>> colMap;
        for (auto& [col, row, val] : nodes) {
            colMap[col].push_back(val);
        }

        vector<vector<int>> result;
        for (auto& [col, vec] : colMap) {
            result.push_back(vec);
        }

        return result;
    }
};
