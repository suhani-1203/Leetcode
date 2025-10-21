class Solution {
public:
    int maxSum = INT_MIN;

    int helper(TreeNode* root) {
        if (!root) return 0;

        int left = max(0, helper(root->left));
        int right = max(0, helper(root->right));

        // possible max path *through* this node
        int through = root->val + left + right;

        // update global maximum
        maxSum = max(maxSum, through);

        // return max downward path (one side only)
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxSum;
    }
};

