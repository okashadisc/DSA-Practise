class Solution {
public:
    unordered_map<int,vector<int>> h;
    int ans;
    
    int dfs(int node,int par,string &s){
        
        int path1=0,path2=0;
        
        auto update= [&](int path){
            
            if(path>=path1){
                
                path2= path1;
                path1= path;
            }
            else if(path>=path2){
                
                path2= path;
            }
        };
        
        
        for(auto nbr: h[node]){
            
            if(par == nbr)continue;
            
            auto steps= dfs(nbr,node,s);
            
            if(s[node] != s[nbr]){
                
                update(steps);
            }
        }
        
        
        ans= max(ans, 1 + path1 + path2);
        
        
        return 1 + (path1);
    }
    void makeGraph(vector<int> &parent,string &s,int n){
        
        for(int i=0;i<n;i++){
            
            h[parent[i]].push_back(i);
            h[i].push_back(parent[i]);
        }
        
        
    }
    int longestPath(vector<int>& parent, string s) {
        int n= s.length();
        
        makeGraph(parent,s,n);
        
        ans= 0;
        dfs(0,-1,s);
        
        return ans;
    }
};