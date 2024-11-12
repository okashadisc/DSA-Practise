class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n= nums.size();
        
        vector<int> dp1(n,1);
        vector<int> dp2(n,1);
        
        for(int i=1;i<n;i++){
            
            if(nums[i]>nums[i-1])dp1[i]= (1 + dp1[i-1]);
            else dp1[i]=1;
        }
        
        for(int i=n-2;i>=0;i--){
            
            if(nums[i]<nums[i+1])dp2[i]= (1 + dp2[i+1]);
            else dp2[i]=1;
        }
        
        
        int ans= INT_MIN;
        for(int i=0;i<n-1;i++){
            
            auto possibleAns= min(dp1[i],dp2[i+1]);
            ans=max(ans,possibleAns);
        }
        
        
//         for(int i=0;i<dp1.size();i++)cout<<dp1[i]<<" ";
//         cout<<endl;
        
//         for(int i=0;i<dp2.size();i++)cout<<dp2[i]<<" ";
//         cout<<endl;
        
        return ans;
        
    }
};