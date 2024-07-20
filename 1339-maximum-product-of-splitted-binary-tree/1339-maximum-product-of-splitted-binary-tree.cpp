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
    unordered_map<TreeNode*,int> subTreeSum;
    long long res;
    long long totalSum;
    long long mod= 1e9 + 7;
    
    void utility(TreeNode* root){
        
        //base case
        if(!root)return;
        
        //recursive case
        
        if(root->left){
            
            long long firstTree= (subTreeSum[root->left]);
            long long secondTree= (long long)totalSum - firstTree;
            
            res=max(res,firstTree*secondTree);
            // res%= mod;
        }
        
        if(root->right){
            
            long long firstTree= (subTreeSum[root->right]);
            long long secondTree= (long long)totalSum - firstTree;
            
            res=max(res,firstTree*secondTree);
            
           // res%= mod;
        }
        
        utility(root->left);
        utility(root->right);
        
    }
    int dfs(TreeNode* root){
        
        //base case
        if(!root)return 0;
        
        //recursive case
        
        totalSum+= (root->val);
        
        auto left= dfs(root->left);
        auto right= dfs(root->right);
        
        return subTreeSum[root]= (left + right + root->val);
    }
    int maxProduct(TreeNode* root) {
        
        totalSum=0;
        dfs(root);
        
        res= LLONG_MIN;
        utility(root);
        
        
        return res%mod;
    }
};