class Solution {
public:
    vector<vector<int>> dp;
    
    int dfs(int indx,vector<int> &nums,int n,int mask){
        
        //base case
        if(indx>n)return dp[indx][mask]= 1;
        
        //recursive case
        if(dp[indx][mask] != (-1))return dp[indx][mask];
        
        long long count=0;
        for(int i=0;i<nums.size();i++){
            
            if(nums[i] % indx == 0 or indx % nums[i] == 0){
                
                if((mask & (1<<i)) == 0){
                    
                    mask|= (1<<i);
                    count+= dfs(indx+1,nums,n,mask);
                    mask&= ~(1<<i);
                }
            }
        }
        
        
        return dp[indx][mask]= count;
    }
    int countArrangement(int n) {
        
        vector<int> nums;
        for(int i=1;i<=n;i++)nums.push_back(i);
        
        dp.resize(20,vector<int>(pow(2,15),-1));
        return dfs(1,nums,n,0);
    }
};