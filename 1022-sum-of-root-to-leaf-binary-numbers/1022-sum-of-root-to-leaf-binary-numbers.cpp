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
    int ans=0;
    void dfs(TreeNode* root,vector<int> subRes){
        
        //base case
        if(!root)return;
        
        //recursive case
        if(!root->left and !root->right){
            
            subRes.push_back(root->val);
            int indx=0;
            int currAns=0;
            for(int i=subRes.size()-1;i>=0;i--){
                
                if(subRes[i]==1)currAns+= (pow(2,indx));
                
                indx+=1;
            }
            
            ans+= currAns;
            return;
        }
        
        subRes.push_back(root->val);
        
        dfs(root->left,subRes);
        dfs(root->right,subRes);
    }
    int sumRootToLeaf(TreeNode* root) {
        
        vector<int> subRes;
        dfs(root,subRes);
        
        
        return ans;
    }
};