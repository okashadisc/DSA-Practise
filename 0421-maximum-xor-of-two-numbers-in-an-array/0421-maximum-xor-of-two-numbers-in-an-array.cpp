struct Node{
    
    Node* links[2];
    
    bool containsKey(int bit){
        
        return links[bit] != NULL;
    }
    
    Node* get(int bit){
        
        return links[bit];
    }
    
    void put(int bit,Node* newNode){
        
        links[bit]= newNode;
    }
};

class Trie{
public:
    
   Node* root;
    
    Trie(){
        
        root= new Node();
    }
    
    void insert(int number){
        
        Node* node= root;
        for(int i=31;i>=0;i--){
            
            int bit= (number>>i) & 1;
            
            if(!node->containsKey(bit)){
                
                node->put(bit,new Node());
            }
            
            node= node->links[bit];
        }
        
    }
    
    int getMaximum(int num){
        
        Node* node= root;
        
        int ans=0;
        for(int i=31;i>=0;i--){
            
            int bit= (num>>i) & 1;
            
            if(node->containsKey(1-bit)){
                
                ans= ans | (1<<i);
                node= node->get(1-bit);
            }
            else{
                
                node= node-> get(bit);
            }
        }
        
        
        return ans;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n= nums.size();
        
        Trie* trie= new Trie();
        
        for(int i=0;i<n;i++){
            
            int number= nums[i];
            trie->insert(number);
        }
        
        int ans= INT_MIN;
        for(int i=0;i<n;i++){
            
            ans=max(ans, trie->getMaximum(nums[i]));
        }
        
        
        return ans;
        
    }
};