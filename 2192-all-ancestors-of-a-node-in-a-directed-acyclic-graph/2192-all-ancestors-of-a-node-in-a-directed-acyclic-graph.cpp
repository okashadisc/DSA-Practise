class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        unordered_map<int,vector<int>> h;
        vector<int> inDegree(n,0);
        
        for(int i=0;i<edges.size();i++){
            
            h[edges[i][0]].push_back(edges[i][1]);
            inDegree[edges[i][1]]+=1;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            
            if(!inDegree[i])q.push(i);
        }
        
        map<int,set<int>> ancestors;
        
        while(!q.empty()){
            
            auto node= q.front();
            q.pop();
            
            for(auto nbr:h[node]){
                
                ancestors[nbr].insert(node);
                inDegree[nbr]-=1;
                
                if(!inDegree[nbr])q.push(nbr);
                
                for(auto ele:ancestors[node]){
                    
                    ancestors[nbr].insert(ele);
                }
            }
        }
        
        
        vector<vector<int>> ans(n);
        
        for(auto i:ancestors){
            
            for(auto ele:i.second){
                
                ans[i.first].push_back(ele);
            }
        }
        
        return ans;
    }
};