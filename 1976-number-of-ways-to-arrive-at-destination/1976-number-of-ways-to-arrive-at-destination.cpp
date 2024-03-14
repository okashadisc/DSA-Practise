typedef pair<long long,long long> node;
const int mod= 1e9 + 7;
class Solution {
public:
    unordered_map<int,vector<node>> h;
    
    void makeGraph(vector<vector<int>> &roads){
        
        for(int i=0;i<roads.size();i++){
            
            h[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            h[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        
        
    }
    int countPaths(int n, vector<vector<int>>& roads){
        
        makeGraph(roads);
        
        set<node> st;
        unordered_map<int,long long> dist;
        vector<long long> dp(n+1,0);
        
        for(int i=0;i<n+1;i++)dist[i]= INT_MAX;
        
        dist[0]=0;
        dp[0]= 1;
        st.insert({0,0});
        
        while(!st.empty()){
            
            auto p= *(st.begin());
            st.erase(st.begin());
            
            long long parent_dist= p.first;
            long long parent= p.second;
            
            for(auto nbr:h[parent]){
                
                long long bacha= nbr.first;
                long long bp_dist= nbr.second;
                
                if(dist[bacha] != INT_MAX){
                    
                    if(parent_dist + bp_dist == dist[bacha]){
                        
                        dp[bacha]= (dp[bacha] + dp[parent])%mod;
                    }
                    if(parent_dist + bp_dist<dist[bacha]){
                        
                        auto address= st.find({dist[bacha],bacha});
                        if(address != st.end()){
                            
                            st.erase(address);
                            dist[bacha]= parent_dist + bp_dist;
                            st.insert({dist[bacha],bacha});
                            
                            dp[bacha]= dp[parent];
                        }  
                    }
                }
                else{
                    
                    dist[bacha]= parent_dist + bp_dist;
                    st.insert({dist[bacha],bacha});
                    dp[bacha]= dp[parent];
                }
                    
            }
        }
        
        
        return dp[n-1];
        
    }
};