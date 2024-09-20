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
    vector<int> largestValues(TreeNode* root) {
         queue<TreeNode*> q;
        
        if(!root)return {};
        q.push(root);
        
        vector<int> res;
        
        while(!q.empty()){
            
            int n= q.size();
            int maxVal= INT_MIN;
            while(n--){
                
                auto node= q.front();
                q.pop();
                
                maxVal=max(maxVal,node->val);
                
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            
            res.push_back(maxVal);
        }
        
        
        
        return res;
    }
};