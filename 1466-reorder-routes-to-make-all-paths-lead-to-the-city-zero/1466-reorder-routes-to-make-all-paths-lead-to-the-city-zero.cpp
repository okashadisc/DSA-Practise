class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> h;
    unordered_map<int,bool> visited;
    
    int dfs(int node,int n){
        
        visited[node]= true;
        
        long long count=0;
        for(auto nbrNode:h[node]){
            
            auto nbr= nbrNode.first;
            auto weight= nbrNode.second;
            
            if(!visited[nbr]){
                
                count+= weight;
                count+= dfs(nbr,n);
            }
        }
        
        
        return count;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        
        for(int i=0;i<connections.size();i++){
            
            h[connections[i][0]].push_back({connections[i][1],1});
            h[connections[i][1]].push_back({connections[i][0],0});
        }
        
        
        return dfs(0,n);
    }
};