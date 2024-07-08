class Solution {
public:
    vector<int> dp;
    int dfs(int indx,vector<int> &energy,int k){
        
        //base case
        if(indx>=energy.size())return 0;
        
        //recursive case
        if(dp[indx] != (-1))return dp[indx];
        
        return dp[indx]= energy[indx] + dfs(indx+k,energy,k);
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int n= energy.size();
        
        int res= INT_MIN;
        
        dp.resize(100005,-1);
        for(int i=0;i<n;i++){
            
            res=max(res,dfs(i,energy,k));
        }
        
        
        return res;
    }
};