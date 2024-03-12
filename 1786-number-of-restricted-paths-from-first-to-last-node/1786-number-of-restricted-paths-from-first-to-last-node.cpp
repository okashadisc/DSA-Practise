typedef pair<int,int> node;
class Solution {
public:
    const long long mod= 1e9 + 7;
    unordered_map<int,vector<node>> h;
    
    void makeGraph(vector<vector<int>> &edges,int n){
        
        for(int i=0;i<edges.size();i++){
            
            h[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            h[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        
    }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
            
        makeGraph(edges,n);
        
        set<node> st;
        unordered_map<int,int> dist;
        
        for(int i=0;i<n;i++)dist[i]= INT_MAX;
        
        
        vector<int> dp(n+1,0);
        
        dist[n]=0;
        dp[n]= 1;
        st.insert({0,n});
        
        while(!st.empty()){
            
            auto p= *(st.begin());
            st.erase(st.begin());
            
            auto parent_dist= p.first;
            auto parent= p.second;
            
            for(auto nbr:h[parent]){
                
                auto bp_dist= nbr.second;
                auto bacha= nbr.first;
                
                if(dist[bacha] != INT_MAX){
                    
                    if(parent_dist + bp_dist<dist[bacha]){
                        
                        auto address= st.find({dist[bacha],bacha});
                        if(address != st.end()){
                            
                            st.erase(address);
                            dist[bacha]= parent_dist + bp_dist;
                            st.insert({dist[bacha],bacha});
                        }
                    }
                    
                }
                else{
                    
                    dist[bacha]= parent_dist + bp_dist;
                    st.insert({dist[bacha],bacha});
                }
                
                if(dist[bacha]>parent_dist){
                    
                    dp[bacha]= (dp[bacha] + dp[parent])%mod;
                }
            }
        }
        
        for(auto i:dist){
            
            cout<<i.first<<"-->"<<i.second<<endl;
        }
        return dp[1];
    }
};