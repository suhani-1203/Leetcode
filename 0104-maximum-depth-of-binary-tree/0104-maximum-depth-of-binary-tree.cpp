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
    int maxDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        queue<TreeNode*> q;
        TreeNode* temp;
        int depth=0;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            temp=q.front();
            q.pop();
            if(temp==NULL){
                depth++;
                if(!q.empty())
                    q.push(NULL);
            }
            else{
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return depth;
    }
};