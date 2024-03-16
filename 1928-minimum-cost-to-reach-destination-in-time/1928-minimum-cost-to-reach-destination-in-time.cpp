typedef pair<int,int> node;
class Solution {
public:
    unordered_map<int,vector<node>> h;
    
    void makeGraph(vector<vector<int>> &edges){
        
        for(int i=0;i<edges.size();i++){
            
            h[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            h[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
    }
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n= passingFees.size();
        
        makeGraph(edges);
        
        multiset<pair<int,node>> st;
        unordered_map<int,int> dist;
        vector<int> dp(n,INT_MAX);
        
        for(int i=0;i<n;i++)dist[i]= INT_MAX;
        
        dp[0]= passingFees[0];
        
        dist[0]=0;
        st.insert({dp[0],{dist[0],0}});
        
        while(!st.empty()){
            
            auto p= *(st.begin());
            st.erase(st.begin());
            
            auto parent_cost= p.first;
            auto parent_dist= p.second.first;
            auto parent= p.second.second;
            
            for(auto nbr:h[parent]){
                
                auto bacha= nbr.first;
                auto bp_dist= nbr.second;
                
                if(dist[bacha] != INT_MAX){
                   
                    if(parent_dist + bp_dist <= maxTime){
                        
                        
                        if(parent_cost + passingFees[bacha]<dp[bacha]){
                            
                            dp[bacha]= parent_cost + passingFees[bacha];
                            dist[bacha]= parent_dist + bp_dist;
                            st.insert({dp[bacha],{dist[bacha],bacha}});
                        }
                        
                        else if(parent_dist + bp_dist <dist[bacha]){
                                dist[bacha]= parent_dist + bp_dist;
                                st.insert({parent_cost + passingFees[bacha],{dist[bacha],bacha}});
                        }
                            
                    }
                }
                else{
                    
                    if(parent_dist + bp_dist <= maxTime){
                        
                        if(parent_cost + passingFees[bacha]<dp[bacha]){
                            dp[bacha]= parent_cost + passingFees[bacha];
                            dist[bacha]= parent_dist + bp_dist;
                            st.insert({dp[bacha],{dist[bacha],bacha}});
                        }
                        
                        else if(parent_dist + bp_dist <dist[bacha]){
                                dist[bacha]= parent_dist + bp_dist;
                                st.insert({parent_cost + passingFees[bacha],{dist[bacha],bacha}});
                        }
                    }
                }
            }
        
        }
        
        return (dp[n-1]==INT_MAX?-1:dp[n-1]);
        
    }
};