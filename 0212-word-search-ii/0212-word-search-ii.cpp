struct Node{
    
    Node* links[26];
    string word;
    bool isEnd;
    
    bool containsKey(int ch){
        
        return links[ch] != NULL;
    }
    
    Node* get(int ch){
        
        return links[ch];
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
    
    void insert(string &word){
        
        Node* node= root;
        
        for(int i=0;i<word.length();i++){
            
            int ch= (word[i]-97);
            
            if(!node->containsKey(ch)){
                
                node->put(ch,new Node());
            }
            
            node= node->links[ch];
            
        }
        
        node->word= word;
        // node->isEnd= true;
        
     }
};
class Solution {
public:
    unordered_set<string> unique;
    vector<string> res;
    
    void dfs(int i,int j,int n,int m,vector<vector<char>> &board,Node* node,string target){
        
        if(i<0 or i>=n or j<0 or j>=m or board[i][j]=='*' or node->links[board[i][j]-97] == NULL)return;
        
        auto ch= board[i][j];
        
        target+= board[i][j];
        node= node-> links[ch-97];
        
        if(target==node->word and !unique.count(target)){
            
            res.push_back(target);
            unique.insert(target);
        }
        
        board[i][j]= '*';
        
        dfs(i-1,j,n,m,board,node,target);
        dfs(i+1,j,n,m,board,node,target);
        dfs(i,j-1,n,m,board,node,target);
        dfs(i,j+1,n,m,board,node,target);
        
        board[i][j]= ch;
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n= board.size();
        int m= board[0].size();
        
        Trie* trie= new Trie();
        
        for(int i=0;i<words.size();i++){
            
            trie->insert(words[i]);
        }
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                Node* node= trie->root;
                string target= "";
                dfs(i,j,n,m,board,node,target);
            }
        }
        
        
        return res;
    }
};