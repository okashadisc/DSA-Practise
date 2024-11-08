struct Node{
    
    Node* links[26];
    bool isWord;
    string word;
    
    bool containsKey(int ch){
        
        return links[ch] != NULL;
    }
    
    Node* get(int ch){
        
        return links[ch];
    }
    
    void put(int ch,Node* newNode){
        
        links[ch]= newNode;
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
            
            int ch= word[i]-97;
            
            if(!node->containsKey(ch)){
                
                node->put(ch,new Node());
            }
            
            node= node->links[ch];
        }
        
        node-> word= word;
        node-> isWord= true;
        
    }
};
class WordDictionary {
public:
    
    bool dfs(Node* node,int indx,string &word,int n,int target){
        
        if(indx>=n){
            
            if(node->isWord)return true;
            
            return false;
        }
        
        if(word[indx] != '.'){
            
            int ch= (word[indx]-97);
            
//             if(ch== (-97)){
                
//                 cout<<"lollll"<<endl;
//                 cout<<indx<<endl;
//                 return false;
//             }
            if(node->containsKey(ch)){
                
                int bit= ch;
                return dfs(node->links[bit],indx+1,word,n,target+1);
            }
            else{
                return false;
            }
        }
        else{
            
            
            for(int i=0;i<26;i++){
                
                if(node->containsKey(i)){
                    
                    if(dfs(node->links[i],indx+1,word,n,target+1))return true;
                }
            }
            
            return false;
        }
        
        
        return false;
    }
    
    Trie* trie= new Trie();
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        
        trie->insert(word);
        
    }
    
    bool search(string word) {
        int n= word.length();
        
        Node* node= trie->root;
        
        return dfs(node,0,word,n,0);
        
    }
    
    void print(string word){
        
        Node* node= trie->root;
        
        while(node){
            
            for(int i=0;i<26;i++){
                
                if(node->links[i] != NULL){
                    
                    cout<<i<<endl;
                    node= node->links[i];
                    break;
                }
            }
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */