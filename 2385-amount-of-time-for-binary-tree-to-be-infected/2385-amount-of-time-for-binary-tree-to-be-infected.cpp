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
    unordered_map<TreeNode*,TreeNode*> parent;
    TreeNode* startNode;
    
    void findPar(TreeNode* root,int start){
        
        //base case
        if(!root)return;
        
        //recursive case
        
        if(root->val==start)startNode= root;
        
        if(root->left){
            
            parent[root->left]= root;
            findPar(root->left,start);
        }
        
        if(root->right){
            
            parent[root->right]= root;
            findPar(root->right,start);
        }
        
    }
    int amountOfTime(TreeNode* root, int start) {
        if(!root)return 0;
        
        findPar(root,start);
                
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> visited;
        q.push(startNode);
        visited[startNode]= true;
        
        int steps=0;
        while(!q.empty()){

            
            int n= q.size();
            while(n--){
                
                auto node= q.front();
                q.pop();
                
                if(node->left and !visited[node->left]){
                    
                    visited[node->left]= true;
                    q.push(node->left);
                }
                
                if(node->right and !visited[node->right]){
                    
                    visited[node->right]= true;
                    q.push(node->right);
                }
                
                if(parent.count(node) and !visited[parent[node]]){
                    
                    visited[parent[node]]= true;
                    q.push(parent[node]);
                }
            }
            
            steps+=1;
        }
        
        
        return steps-1;
    }
};