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
class BSTIterator {
public:
    stack<TreeNode*>st;
    void pushAll(TreeNode* temp)
    {
        while(temp)
        {
            st.push(temp);
            temp=temp->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        auto node=st.top();
        st.pop();
        pushAll(node->right);
        return node->val;
        
    }
    
    bool hasNext() {
        return !st.empty();
        
    }
};
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        BSTIterator bst1(root1);
        BSTIterator bst2(root2);
        
        vector<int> ans;
        while(!bst1.st.empty() or !bst2.st.empty()){
            
            if(bst2.st.empty() or (!bst1.st.empty() and bst1.st.top()->val < bst2.st.top()->val)){
                
                auto node= bst1.next();
                ans.push_back(node);
            }
            else{
                
                auto node= bst2.next();
                ans.push_back(node);
            }
        }
        
        
        return ans;
    }
};