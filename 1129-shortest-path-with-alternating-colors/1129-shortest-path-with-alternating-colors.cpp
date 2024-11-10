typedef pair<int,int> node;
class Solution {
public:
    unordered_map<int,vector<node>> h;
    vector<vector<bool>> visited;
    vector<int> ans;
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        for(int i=0;i<redEdges.size();i++){
            
            h[redEdges[i][0]].push_back({redEdges[i][1],0});
        }
        
        for(int i=0;i<blueEdges.size();i++){
            
            h[blueEdges[i][0]].push_back({blueEdges[i][1],1});
        }
        
        queue<pair<int,node>> q;
        visited.resize(n,vector<bool>(2,false));
        
        visited[0][0]= true;
        visited[0][1]= true;
        ans.resize(n,-1);
        
        q.push({0,{0,0}});
        q.push({0,{1,0}});
        
        while(!q.empty()){
            
            auto ele= q.front();
            q.pop();
            
            auto node= ele.first;
            auto color= ele.second.first;
            auto steps= ele.second.second;
            
            if(ans[node] == (-1))ans[node]= steps;
            
            
            for(auto nbrNode:h[node]){
                
                auto nbr= nbrNode.first;
                auto nextColor= nbrNode.second;
                
                if(color != nextColor and !visited[nbr][nextColor]){
                    
                    visited[nbr][nextColor]= true;
                    q.push({nbr,{nextColor,steps+1}});
                }
            }
        }
        
        
        return ans;
    }
};