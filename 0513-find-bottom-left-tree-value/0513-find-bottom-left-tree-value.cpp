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
    int check;
    bool flag;
    int maxHeight;
    
    void dfs(TreeNode* root,int height){
        
        //base case
        if(!root)return;
        
        //recurisve case
        height+=1;
       
        
      
        if(height>maxHeight and !root->left and !root->right){
            
            maxHeight= height;
            flag= true;
            check= root->val;
            return;
        }
        if(!root->left and !root->right and !flag){
            check= root->val;
            return;
        }
        
        dfs(root->left,height);
        dfs(root->right,height);
        
    }
    int findBottomLeftValue(TreeNode* root) {
        
        check= (-1);
        
        maxHeight= INT_MIN;
        flag= false;
        dfs(root,0);
        
        return check;
    }
};