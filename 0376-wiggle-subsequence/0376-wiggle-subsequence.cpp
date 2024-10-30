class Solution {
public:
    vector<vector<vector<int>>> dp;
    int dfs(int indx,int prevIndx,bool isIncreasing,vector<int> &nums,int n){
        
        //base case
        if(indx>=n)return 0;
        
        //recursive case
        if(dp[indx][prevIndx+1][isIncreasing] != (-1))return dp[indx][prevIndx+1][isIncreasing];
        
        int option1= 0 + dfs(indx+1,prevIndx,isIncreasing,nums,n);
        
        int option2=0;
        
        if(prevIndx==(-1)){
            
        return dp[indx][prevIndx+1][isIncreasing]= 1 + max(dfs(indx+1,indx,true,nums,n),dfs(indx+1,indx,false,nums,n));
        }
        
        if(nums[indx]==0 and nums[prevIndx]==0)return 0 + dfs(indx+1,prevIndx,isIncreasing,nums,n);
        
        if(nums[indx]>nums[prevIndx] and !isIncreasing){
            
            option2= 1 + dfs(indx+1,indx,true,nums,n);
        }
        else if(nums[indx]<nums[prevIndx] and isIncreasing){
            
            option2= 1 + dfs(indx+1,indx,false,nums,n);
        }
        
        
        return dp[indx][prevIndx+1][isIncreasing]= max(option1,option2);
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n= nums.size();
        
        if(n==2){
            
            if(nums[0]<nums[1])return 2;
            if(nums[0]>nums[1])return 2;
        }
        if(n==1 or n==2)return 1;
        
        dp.resize(n+5,vector<vector<int>>(n+5,vector<int>(2,-1)));
        return max(dfs(0,-1,false,nums,n),dfs(0,-1,false,nums,n));
        
        
    }
};