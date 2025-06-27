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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        int maxWidth=0;

        while(!q.empty()){
            int currLevelSize=q.size();
            unsigned long long stIndex=q.front().second;
            unsigned long long endIndex=q.back().second;
            maxWidth=max(maxWidth,(int)(endIndex-stIndex+1));

            for(int i=0;i<currLevelSize;i++){
                auto currNode=q.front();
                q.pop();

                if(currNode.first->left)
                    q.push({currNode.first->left,currNode.second*2+1});
                if(currNode.first->right)
                    q.push({currNode.first->right,currNode.second*2+2});
            }
        }
        return maxWidth;
    }
};