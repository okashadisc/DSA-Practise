class Solution {
public:
    unordered_map<int,vector<int>> graph1;
    unordered_map<int,vector<int>> graph2;
    vector<int> resOfTree1;
    vector<int> resOfTree2;
    
    int dfsOnTree2(int node,int edgeCount,int k,unordered_map<int,vector<int>> &h,vector<bool> &visited){
        
        if(edgeCount>k)return 0;
        
        long long count=1;
        visited[node]= true;
        
        for(auto nbr:h[node]){
            
            if(edgeCount<=k){
                
                if(!visited[nbr])count+= dfsOnTree2(nbr,edgeCount+1,k,h,visited);
            }
        }
        
        
        return count;
    }
    int dfsOnTree1(int node,int edgeCount,int k,unordered_map<int,vector<int>> &h,vector<bool> &visited){
        if(edgeCount>k)return 0;
        
        long long count=1;
        visited[node]= true;
        
        for(auto nbr:h[node]){
            
            if(edgeCount<=k){
                
                if(!visited[nbr])count+= dfsOnTree1(nbr,edgeCount+1,k,h,visited);
            }
        }
        
        // resOfTree1[node]= count;
        
        return count;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n= edges1.size();
        int m= edges2.size();
        
        
        for(int i=0;i<edges1.size();i++){
            
            graph1[edges1[i][0]].push_back(edges1[i][1]);
            graph1[edges1[i][1]].push_back(edges1[i][0]);
        }
        
        for(int i=0;i<edges2.size();i++){
            
            graph2[edges2[i][0]].push_back(edges2[i][1]);
            graph2[edges2[i][1]].push_back(edges2[i][0]);
        }
        
        int maxLen= max(n,m);
        resOfTree1.resize(n+1,0);
        if(k==0){
            
            for(int i=0;i<=n;i++)resOfTree1[i]=1;
            
            return resOfTree1;
        }
        
        
        for(int i=0;i<=n;i++){
            
            vector<bool> visited1(n+1,false);
            resOfTree1[i]+= dfsOnTree1(i,0,k,graph1,visited1);
        }
        
        resOfTree2.resize(m+1,0);
        for(int i=0;i<=m;i++){
            
            vector<bool> visited2(m+1,false);
            resOfTree2[i]+= dfsOnTree2(i,1,k,graph2,visited2);
        }
        
//         for(int i=0;i<=n;i++)cout<<resOfTree1[i]<<" ";
        
//         cout<<endl;
        
//         for(int i=0;i<=m;i++)cout<<resOfTree2[i]<<" ";
//         cout<<endl;
        
        for(int i=0;i<=n;i++){
            
            int maxVal=0;
            for(int j=0;j<=m;j++){
                
                maxVal=max(maxVal,resOfTree1[i] + resOfTree2[j]);
            }
            
            resOfTree1[i]= maxVal;
        }
        
        return resOfTree1;
        
    }
};