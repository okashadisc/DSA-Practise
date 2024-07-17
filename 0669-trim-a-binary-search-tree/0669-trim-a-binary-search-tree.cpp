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
    TreeNode* dfs(TreeNode* root,int low,int high){
        
        //base case
        if(!root)return NULL;
        
        //recursive case
        
        root->left= dfs(root->left,low,high);
        root->right= dfs(root->right,low,high);
        
        if(root->val<low or root->val>high){
            
            if(root->left)return root->left;
            if(root->right)return root->right;
            
            return NULL;
        }
        
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        return dfs(root,low,high);
    }
};