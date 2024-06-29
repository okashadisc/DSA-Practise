class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n= nums.size();
        
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            
            dp[i]= nums[i];
        }
        
        int maxSum=0;
        for(int i=1;i<n;i++){
            
            if(nums[i]>nums[i-1])dp[i]+= (dp[i-1]);
        }
        
        maxSum= *max_element(dp.begin(),dp.end());
        
        
        return maxSum;
    }
};