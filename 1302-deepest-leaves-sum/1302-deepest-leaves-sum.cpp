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
    int maxHeight= INT_MIN;
    int sum;
    
    void dfs(TreeNode* root,int height){
        
        //base case
        if(!root)return;
        
        if(!root->left and !root->right){
            
            if(height>maxHeight){
                
                maxHeight= height;
                sum= (root->val);
                return;
            }
            
            if(height==maxHeight)sum+= (root->val);
        }
        
        //recursive case
        
        dfs(root->left,height+1);
        dfs(root->right,height+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        
        sum=0;
        dfs(root,0);
        
        return sum;
    }
};