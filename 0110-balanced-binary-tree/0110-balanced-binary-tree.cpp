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
int checkLength(TreeNode* root){
    if(!root)
        return 0;
    int right=checkLength(root->right);
    if(right==-1) return -1;

    int left=checkLength(root->left);
    if(left==-1) return -1;

    if(abs(right-left)>1)
        return -1;

    return 1+max(right,left);
}
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)
            return true;
        if(checkLength(root)!=-1)
            return true;
        return false;
    }
};