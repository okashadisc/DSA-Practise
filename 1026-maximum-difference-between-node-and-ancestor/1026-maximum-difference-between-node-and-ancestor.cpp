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
    int ans= INT_MIN;
    
    void dfs(TreeNode* root,int mx,int mi){
        
        //base case
        if(!root)return;
        
        //recursive case
        
        mi=min(mi,root->val);
        mx=max(mx,root->val);
        
        ans=max(ans,abs(mx-mi));
        
        
        dfs(root->left,mx,mi);
        dfs(root->right,mx,mi);
        
    }
    int maxAncestorDiff(TreeNode* root) {
        
        int mx= INT_MIN;
        int mi= INT_MAX;
        
        dfs(root,mx,mi);
        
        return ans;
    }
};