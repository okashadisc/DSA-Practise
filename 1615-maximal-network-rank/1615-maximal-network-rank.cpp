class Solution {
public:
    vector<vector<int>> graph;
    
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<int> inDegree(n,0);
        graph.resize(n,vector<int>(n,0));
        
        for(int i=0;i<roads.size();i++){
            
            inDegree[roads[i][0]]+=1;
            inDegree[roads[i][1]]+=1;
            graph[roads[i][0]][roads[i][1]]+=1;
            graph[roads[i][1]][roads[i][0]]+=1;
        }
        
        int ans= INT_MIN;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<n;j++){
                
                if(j != i)ans=max(ans,inDegree[i] + inDegree[j] - graph[i][j]);
            }
        }
        
        
        return ans;
    }
};