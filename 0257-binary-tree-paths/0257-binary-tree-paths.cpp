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
    void findPaths(TreeNode* root, string temp,vector<string>& paths){
        if(root->left==NULL && root->right==NULL){
            temp+=to_string(root->val);
            paths.push_back(temp);
            return;
        }
        temp+=(to_string(root->val)+"->");
        if(root->left) findPaths(root->left,temp,paths);
        if(root->right) findPaths(root->right,temp,paths);
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        findPaths(root,"",paths);
        return paths;

    }
};