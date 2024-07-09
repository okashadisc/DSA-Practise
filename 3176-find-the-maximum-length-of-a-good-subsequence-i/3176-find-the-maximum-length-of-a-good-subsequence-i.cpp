class Solution {
public:
    int dp[6005][105];
    int dfs(int i,int alternateParity,vector<int> &nums,int k){
        int n= nums.size();
        
        //base case
        if(i>=n)return 0;
        
        //recursive case
        if(dp[i][alternateParity] != (-1))return dp[i][alternateParity];
        
        int ans=0;
        for(int j=i+1;j<n;j++){
            
            if(alternateParity<k and nums[i] != nums[j])ans=max(ans,1 + dfs(j,alternateParity+1,nums,k));
            else if(nums[i]==nums[j])ans=max(ans,1 + dfs(j,alternateParity,nums,k));
            
        }
        
        
        return dp[i][alternateParity]= ans;
    }
    int maximumLength(vector<int>& nums, int k) {
        int n= nums.size();
        
        // dp.resize(5005,vector<int>(105,-1));
        
        memset(dp,-1,sizeof(dp));
        int res=0;
        for(int i=0;i<n;i++){
            
            res=max(res,1 + dfs(i,0,nums,k));
        }
        
        
        return res;
    }
};