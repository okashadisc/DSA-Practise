class Solution {
public:
    vector<vector<int>> dp;
    
    int dfs(int i,int mod,vector<int> &nums,int k){
        int n= nums.size();
        
        //base case
        if(i>=n)return 0;
        
        //recursive case
        if(dp[i][mod] != (-1))return dp[i][mod];
        
        int ans=0;
        for(int j=i+1;j<n;j++){
            
            if((nums[j] + nums[i]) % k == mod){
                ans=max(ans,1 + dfs(j,(nums[i] + nums[j]) % k,nums,k));
                break;
            }
        }
        
        
        return dp[i][mod]= ans;
    }
    int maximumLength(vector<int>& nums, int k) {
        int n= nums.size();
        dp.resize(n+1,vector<int>(k+1,-1));
        
        int ans= 0;
        for(int i=0;i<n-1;i++){
            
            for(int j=i+1;j<n;j++){
                
                ans=max(ans,1 + dfs(j,(nums[i] + nums[j]) % k,nums,k));
            }
        }
        
        
        return (ans+1);
    }
};