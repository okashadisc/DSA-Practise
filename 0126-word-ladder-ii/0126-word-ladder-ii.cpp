class Solution {
public:
    unordered_map<string,int> dist;
    vector<vector<string>> ans;
    
    // By Doing a DFS Traversal we are just moving backWards from   (beginWord)  <-- (prevWord) <-- (word) <--  (endWord)
    
    void dfs(string &word,vector<string> &currAns,string &beginWord){
        
        //base case
        if(word == beginWord){
            
            reverse(currAns.begin(),currAns.end());
            ans.push_back(currAns);
            reverse(currAns.begin(),currAns.end());
            return;
        }
        
        //recursive case
        
        auto distOfWordFromEndWord= dist[word];
        
        for(int i=0;i<word.length();i++){
            
            auto ch= word[i];
            
            for(char j='a';j<='z';j++){
                
                    word[i]= j;
                    
                    if(dist.find(word) != dist.end()){
                        
                        auto prevWord= word;
                        if(dist[prevWord] + 1 == distOfWordFromEndWord){
                            
                            currAns.push_back(word);
                            dfs(word,currAns,beginWord);
                            currAns.pop_back();
                        }
                    }
            }
            
            word[i]= ch;
        }
        
        
    }
    void BFS(string &beginWord,string &endWord,unordered_set<string> &st){
        
        queue<string> q;
        q.push(beginWord);
        
        auto address= st.find(beginWord);
        if(address != st.end())st.erase(address);
        int steps=0;
        
        while(!q.empty()){
            int n= q.size();
            
            while(n--){
                
                auto word= q.front();
                q.pop();
                
             if(word==endWord){
                dist[word]= steps;
                break;
                }
                dist[word]= steps;
                for(int i=0;i<word.length();i++){
                
                    auto ch= word[i];
                    for(char j='a';j<='z';j++){
                            
                        if(ch != j){
                            word[i]= j;
                            if(st.find(word) != st.end()){
                                
                                cout<<word<<" ";
                                // if(word=="hot")cout<<"Yes"<<endl;
                                auto address= st.find(word);
                                if(address != st.end())st.erase(address);
                                q.push(word);
                            }
                        }
                    }
                    
                    word[i]= ch;
                }
            }
            cout<<endl;
            
            steps+=1;
        }

    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        dist[beginWord]= 0;
        
        unordered_set<string> st(wordList.begin(),wordList.end());
        
        unordered_set<string> another= st;
        BFS(beginWord,endWord,another);
        
        for(auto i:dist)cout<<i.first<<"-->"<<i.second<<endl;
        
        if(dist.find(endWord) != dist.end()){
            
            vector<string> currAns;
        
            currAns.push_back(endWord);
            dfs(endWord,currAns,beginWord);
        }
        
        
        return ans;
    }
};