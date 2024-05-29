class Solution {
public:
    int ans= INT_MAX;
    
    void dfs(int curr,int k,vector<int> &children,vector<int> &cookies,int n){
        
        //base case
        if(curr>=n){
            
            int unfairness= INT_MIN;
            for(int i=0;i<k;i++){
                
                unfairness=max(unfairness,children[i]);
            }
            
            ans=min(ans,unfairness);
            return;
        }
        
        //recursive case
        
        // Search Space  [----  k-children  ----]
        
        for(int i=0;i<k;i++){
            
            children[i]+= cookies[curr];
            dfs(curr+1,k,children,cookies,n);
            children[i]-= cookies[curr];
        }
        
        
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int n= cookies.size();
        
        vector<int> children(k,0);
        
        dfs(0,k,children,cookies,n);
        
        return ans;
    }
};