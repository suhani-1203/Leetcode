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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> nodeMap;
        unordered_set<int> children;
        
        for(auto& d:descriptions){
            int parentVal=d[0];
            int childVal=d[1];
            bool isLeft=d[2]==1;

            if(nodeMap.find(parentVal)==nodeMap.end())
                nodeMap[parentVal]=new TreeNode(parentVal);
            
            TreeNode * parentNode=nodeMap[parentVal];

            if(nodeMap.find(childVal)==nodeMap.end())
                nodeMap[childVal]=new TreeNode(childVal);
            
            TreeNode* childNode= nodeMap[childVal];

            if(isLeft)
                parentNode->left=childNode;
            else
                parentNode->right=childNode;

            children.insert(childVal);

        }
        for(auto& d:descriptions){
            int parentVal=d[0];
            if(children.find(parentVal)==children.end())
                return nodeMap[parentVal];
        }
        return nullptr;
    }
};