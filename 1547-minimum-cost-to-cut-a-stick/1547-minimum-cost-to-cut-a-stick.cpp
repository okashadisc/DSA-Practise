class Solution {
public:
    vector<vector<int>> dp;
    
    int dfs(vector<int> &cuts,int left,int right){
        
        //base case
        
        if(left>right)return dp[left][right]= 0;
        
        //recursive case
        if(dp[left][right] != (-1))return dp[left][right];
        
        int cost= 0;
        int result= INT_MAX;
        
        for(int i=left;i<=right;i++){
            
            cost= cuts[right+1]-cuts[left-1];
            cost+= dfs(cuts,left,i-1) + dfs(cuts,i+1,right);
            
            result=min(result,cost);
        }
        
        return dp[left][right]= result;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        
        cuts.insert(cuts.begin(),0);
        cuts.insert(cuts.end(),n);
        
        int len= cuts.size();
        
        dp.resize(len+1,vector<int>(len+1,-1));
        return dfs(cuts,1,len-2);
        
    }
};