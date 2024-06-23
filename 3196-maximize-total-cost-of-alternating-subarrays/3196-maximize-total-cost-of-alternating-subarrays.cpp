class Solution {
public:
    vector<vector<long long>> dp;
    
    long long dfs(int indx,int flag,vector<int> &nums){
        
        if(indx<0)return 0;
        
        if(indx==0){
            
            if(flag==0)return dp[indx][flag]= nums[0];
            else return dp[indx][flag]= INT_MIN;
        }
        
        if(dp[indx][flag] != (-1))return dp[indx][flag];
        long long ans= INT_MIN;
        
        if(flag==0){
            
            // long long option1= nums[indx] + dfs(indx-1,0,nums);
            // long long option2= nums[indx] + dfs(indx-1,1,nums);
            
            ans=max(ans,nums[indx] + dfs(indx-1,0,nums));
            
            ans=max(ans,nums[indx] + dfs(indx-1,1,nums));
        }else{
            
            ans=max(ans,-nums[indx]+dfs(indx-1,0,nums));
        }
        
        
        return dp[indx][flag]= ans;
    }
    long long maximumTotalCost(vector<int>& nums) {
        int n= nums.size();
        
        dp.resize(n,vector<long long>(2,-1));
        
        return max(dfs(n-1,0,nums),dfs(n-1,1,nums));
    }
};