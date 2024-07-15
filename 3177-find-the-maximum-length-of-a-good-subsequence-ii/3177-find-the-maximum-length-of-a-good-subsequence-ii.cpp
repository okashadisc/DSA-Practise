class Solution {
public:
    unordered_map<int,vector<int>> duplicate;
    vector<vector<vector<int>>> dp;
        
    int customUpperBound(vector<int> &indices,int si){
        
        return upper_bound(indices.begin(),indices.end(),si) - indices.begin();
    }
    int dfs(int indx,int alternateParity,vector<int> &nums,int k,int tight){
        int n= nums.size();
        
        //base case
        if(indx>=n)return 0;
        if(alternateParity>k)return 0;
        
        //recursive case
        if(dp[indx][alternateParity][tight] != (-1))return dp[indx][alternateParity][tight];
        
        int nextIndx= customUpperBound(duplicate[nums[indx]],indx);
        
        int ans=0;
        
        if(nextIndx<duplicate[nums[indx]].size())ans=max(ans,1 + dfs(duplicate[nums[indx]][nextIndx],alternateParity,nums,k,1));
        else ans=max(ans,1 + dfs(n,alternateParity,nums,k,0));
        
        if(alternateParity<k)ans=max(ans,1 + dfs(indx+1,alternateParity+1,nums,k,0));
        
        if(tight)if(alternateParity<k)ans=max(ans,1 + dfs(indx+1,alternateParity+1,nums,k,0));
        
        if(!tight)ans=max(ans,0 + dfs(indx+1,alternateParity,nums,k,0));
        
        
        return dp[indx][alternateParity][tight]= ans;
    }
    int maximumLength(vector<int>& nums, int k) {
        int n= nums.size();
        
        for(int i=0;i<n;i++)duplicate[nums[i]].push_back(i);
        
        dp.resize(n,vector<vector<int>>(51,vector<int>(2,-1)));
        return dfs(0,0,nums,k,0);
    }
};