class Solution {
public:
    int dp[200005][3];
    int dfs(int indx,bool lastIndxEven,vector<int> &nums){
        int n= nums.size();
        
        //base case
        if(indx>=n)return 0;
        
        //recurivse case
        if(dp[indx][lastIndxEven] != (-1))return dp[indx][lastIndxEven];
        
        int option1=0,option2=0;
        
        // Principle of Inclusion-Exclusion
        
        option1= 0 + dfs(indx+1,lastIndxEven,nums);
        
        if((lastIndxEven and nums[indx] % 2 != 0) or (!lastIndxEven and nums[indx] % 2 == 0))option2= 1 + dfs(indx+1,nums[indx] % 2 == 0,nums);
        
        return dp[indx][lastIndxEven]= max(option1,option2);
    }
    int maximumLength(vector<int>& nums) {
        int n= nums.size();
        
        memset(dp,-1,sizeof(dp));
        int alternateParity= max(dfs(0,false,nums),dfs(0,true,nums));
        
        int even= 0;
        int odd= 0;
        
        for(int i=0;i<n;i++){
            
            if(nums[i] & 1)odd+=1;
            else even+=1;
        }
        
        
        return max({alternateParity,odd,even});
    }
};