class Solution {
public:
    vector<long long> dp;
    
    long long dfs(int indx,vector<int> &nums,int k){
        int n= nums.size();
        
        //base case
        if(indx>n-3)return 0;
        
        //recursive case
        if(dp[indx] != (-1))return dp[indx];
        
        long long ans= LLONG_MAX;
        for(int i=indx;i<indx+3;i++){
            
            ans=min(ans, max(0,k-nums[i]) + dfs(i+1,nums,k));
        }
        
        return dp[indx]= ans;
    }
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n= nums.size();
        
        dp.resize(n,-1);
        return dfs(0,nums,k);
    }
};