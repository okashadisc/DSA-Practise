class Solution {
public:
    unordered_map<int,vector<int>> h;
    
    void dfs(int node,unordered_set<int> &components){
        
        if(components.find(node) == components.end()){
            
            components.insert(node);
            
            for(auto nbr:h[node]){
                
                if(!components.count(nbr)){
                    
                    dfs(nbr,components);
                }
            }
        }
        
        
    }
    void makeGraph(vector<vector<int>> &bombs,int n){
        
        for(int i=0;i<n;i++){
            
            int radius= bombs[i][2];
            long long x1= bombs[i][0];
            long long y1= bombs[i][1];
            
            for(int j=0;j<n;j++){
                
                long long x2= bombs[j][0];
                long long y2= bombs[j][1];
                if(j != i and (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) <= (long long)radius*radius){
                    
                    h[i].push_back(j);
                }
            }
        }
        
        
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n= bombs.size();
        
        makeGraph(bombs,n);
        
        int ans= 0;
        for(int i=0;i<n;i++){
            
            unordered_set<int> components;
            dfs(i,components);
            int numberOfComponents= components.size();
            cout<<components.size()<<endl;
            ans=max(ans,numberOfComponents);
            components.clear();
        }
        
        return ans;
    }
};