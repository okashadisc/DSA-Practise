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
    bool isCompleteTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            
            
                auto node= q.front();
                q.pop();
                
                if(node==NULL)break;
                
                q.push(node->left);
                q.push(node->right);
        }
        
        
        while(q.front() == NULL)q.pop();
        
        
        if(q.empty())return true;
        
        
        return false;
    }
};