class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n= cuboids.size();
        
        vector<int> dp(n,0);
        
        // Sort Indivisual boxes to set height as (max) for each box
        for(int i=0;i<n;i++){
            
            sort(cuboids[i].begin(),cuboids[i].end());
        }
        
        
        sort(cuboids.begin(),cuboids.end());
        int mx= 0;
        
        for(int i=0;i<n;i++){
            
            dp[i]= cuboids[i][2];
            for(int j=i-1;j>=0;j--){
                
                if(cuboids[j][0]<=cuboids[i][0] and cuboids[j][1]<=cuboids[i][1] and cuboids[j][2]<=cuboids[i][2]){
                    
                    auto possibleAns= dp[j] + cuboids[i][2];
                    dp[i]=max(dp[i],possibleAns);
                }
            }
                mx=max(mx,dp[i]);
        }
        
        return mx;
    }
};