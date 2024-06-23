class DSU{
public:
    
    vector<int> rank;
    vector<int> parent;
    
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
        
        if(rank[u]>rank[v]){
            
            parent[v]= u;
        }
        else if(rank[v]>rank[u]){
            
            parent[u]= v;
        }
        else{
            
            parent[v]= u;
            rank[u]+=1;
        }
        
    }
};
class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b){
        
        return a[2]<b[2];
    }
    
    int minimumSpanningTree(vector<vector<int>> &edges,int n,int skip,int addEdge){
        
        DSU uf(n);
        int weight= 0;
        
        if(addEdge != (-1)){
            
            uf.Union(edges[addEdge][0],edges[addEdge][1]);
            weight+= (edges[addEdge][2]);
        }
        
        
        for(int i=0;i<edges.size();i++){
            
            if(i==skip)continue;
            
            auto u= edges[i][0];
            auto v= edges[i][1];
            
            if(uf.findPar(u) != uf.findPar(v)){
                
                uf.Union(u,v);
                weight+= edges[i][2];
            }
        }
        
        int parentNode= uf.findPar(edges[0][0]);
        
        for(int i=0;i<n;i++){
            
            if(uf.findPar(i) != parentNode)return INT_MAX;
        }
        
        
        return weight;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        
        for(int i=0;i<edges.size();i++)edges[i].push_back(i);
        
        sort(edges.begin(),edges.end(),comp);
        vector<vector<int>> res;
        
        int originalMSTweight= minimumSpanningTree(edges,n,-1,-1);
        cout<<originalMSTweight<<endl;
        
        //   Now to find (criticalEdge) we try to skip every (edge) one by one and 
        //   we check the weight of the MST generated
        
        vector<int> criticalEdges;
        vector<int> pseudoCriticalEdges;
        
        for(int i=0;i<edges.size();i++){
            
            int weightMSTformedBySkippingNode= minimumSpanningTree(edges,n,i,-1);
            
            int weightofMSTformedByForceAddingEdge= minimumSpanningTree(edges,n,-1,i);
            
            if(weightMSTformedBySkippingNode>originalMSTweight){
                
                criticalEdges.push_back(edges[i][3]);
            }
            
            else if(weightofMSTformedByForceAddingEdge==originalMSTweight){
                
                pseudoCriticalEdges.push_back(edges[i][3]);
            }
        }
        
        res.push_back(criticalEdges);
        res.push_back(pseudoCriticalEdges);
        
        return res;
    }
};