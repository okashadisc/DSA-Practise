class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int n,int k){
        //base case
        if(n==0 and k>=2)return dp[n][k]=1;
        
        //recursive case
        if(dp[n][k] != (-1))return dp[n][k];
        
        int ans= INT_MIN;
        for(int j=1;j<=n;j++){
            int sikka= j;
            if(n-sikka>=0){
                int chotiAmount= n-sikka;
                int chotiAmountKeSikke= dfs(chotiAmount,k+1);
                if(chotiAmountKeSikke != INT_MIN){
                    ans= max(ans,chotiAmountKeSikke*sikka);
                }
            }
        }
        
        return dp[n][k]=ans;
    }
    int integerBreak(int n) {
        
        int k=0;
        dp.resize(60,vector<int>(1005,-1));
        return dfs(n,k);
        
    }
};