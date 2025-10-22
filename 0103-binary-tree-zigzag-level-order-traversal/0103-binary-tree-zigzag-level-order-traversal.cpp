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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*> levelT;
        levelT.push(root);

        vector<vector<int>>ans;
        int flag=0;

        while(!levelT.empty()){
            int n=levelT.size();
            vector<int> level;

            for(int i=0;i<n;i++){
                TreeNode* temp=levelT.front();
                levelT.pop();
                level.push_back(temp->val);

                if(temp->left) levelT.push(temp->left);
                if(temp->right) levelT.push(temp->right);
            }
            if(flag)
                reverse(level.begin(),level.end());
            
            ans.push_back(level);
            flag=!flag;
        }
        return ans;
    }
};