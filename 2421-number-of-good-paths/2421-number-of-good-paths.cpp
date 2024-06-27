class DSU{
public:
    vector<int> parent;
    vector<int> rank;
    
    DSU(int n){
        
        parent.resize(n,0);
        rank.resize(n,0);
        
        for(int i=0;i<n;i++)parent[i]= i;
        
    }
    
    int findPar(int node){
        
        if(node==parent[node])return node;
        
        return parent[node]= findPar(parent[node]);
    }
    
    void Union(int u,int v){
        
        u= findPar(u);
        v= findPar(v);
        
        if(u==v)return;
        
        if(rank[u]>rank[v])parent[v]= u;
        
        else if(rank[v]>rank[u])parent[u]= v;
        else{
            
            rank[u]+=1;
            parent[v]= u;
        }
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n= vals.size();
        
        vector<bool> isActive(n);
        
        map<int,vector<int>> val_to_node;
        for(int i=0;i<n;i++){
            
            val_to_node[vals[i]].push_back(i);
        }
        
        // Form the graph
        unordered_map<int,vector<int>> graph;
        for(int i=0;i<n;i++)graph[i];
        
        for(int i=0;i<edges.size();i++){
            
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        
        // I will go to every (value) from (smaller) to (greater)
        
        DSU uf(n);
        
        int validPaths=0;
        validPaths+= (n);
        
        for(auto i:val_to_node){
            
           auto value= i.first;
            
            for(auto node: i.second){
                
              for(auto nbr:graph[node]){
                    
                    if(isActive[nbr])uf.Union(nbr,node);
               }
                isActive[node]= true;
            }
            
            vector<int> leaders;
            
            for(int node:i.second)leaders.push_back(uf.findPar(node));
            
            sort(leaders.begin(),leaders.end());
            
            cout<<endl;
            
            int count=1;
            int prev= (-1);
            if(leaders.size())prev= leaders[0];
            
            for(int j=1;j<leaders.size();j++){
                
                 if(leaders[j]==prev)count+=1;
                 else if(leaders[j] != prev){
                    
                    validPaths+= (count*(count-1))/2;
                    prev= (leaders[j]);
                    count=1;
                 }
            }
            
            validPaths+= (count*(count-1))/2;
        }
        
        return validPaths;
    }
};