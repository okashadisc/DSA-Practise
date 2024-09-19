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
    unordered_set<int> valid;
    int maxDepth;
    vector<TreeNode*> res;
    
    void dfs(TreeNode* root,int height){
        
        //base case
        if(!root)return;
        
        //recursive case
        
        height+=1;
        if(!root->left and !root->right and height==maxDepth){
            
            valid.insert(root->val);
            return;
        }
        if(!root->left and !root->right and height>maxDepth){
            
            valid.clear();
            maxDepth= height;
            valid.insert(root->val);
            return;
        }
        
        dfs(root->left,height);
        dfs(root->right,height);
        
    }
    
    TreeNode* utility(TreeNode* root){
        
        //base case
        if(!root)return NULL;
        
        //recursive case
        
        if(valid.count(root->val))return root;
        
        auto left= utility(root->left);
        auto right= utility(root->right);
        
        if(left and right)return root;
        
        if(left and !right)return left;
        
        if(!left and right)return right;
        
        return NULL;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root->left and !root->right)return root;
        
        if(!root)return NULL;
        
        maxDepth= 0;
        dfs(root,0);
        
       return utility(root);
    }
};