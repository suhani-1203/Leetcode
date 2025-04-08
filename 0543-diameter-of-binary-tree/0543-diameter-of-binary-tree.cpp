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
    int res=0;
    int calcLength(TreeNode* root){
        if(!root)
            return 0;
        int left=calcLength(root->left);
        int right=calcLength(root->right);

        res=max(res,left+right);

        return 1+(max(left,right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        calcLength(root);
        return res;
    }
};