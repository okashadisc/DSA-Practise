class ThroneInheritance {
public:
    unordered_map<string,vector<string>> graph;
    unordered_set<string> dead;
    vector<string> inheritance;
    string currKing;
    
    void dfs(string node,vector<string> &ans,unordered_map<string,bool> &visited){
        
        if(dead.find(node) == dead.end())ans.push_back(node);
        
        for(auto nbr:graph[node]){
            
            if(!visited[nbr]){
                
                visited[nbr]= true;
                dfs(nbr,ans,visited);
            }
        }
    
    }
    ThroneInheritance(string kingName) {
        
        currKing= kingName;
    }
    
    void birth(string parentName, string childName) {
        
        graph[parentName].push_back(childName);
    }
    
    void death(string name) {
        
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        
        unordered_map<string,bool> visited;
        vector<string> ans;
        dfs(currKing,ans,visited);
        
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */