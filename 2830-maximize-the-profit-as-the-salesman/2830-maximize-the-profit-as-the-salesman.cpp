class Solution {
public:

    vector<int> dp;
    static bool comp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0])return a[1]<b[1];
        
        return a[0]<b[0];
    }
    
    int customUpperBound(int indx,vector<vector<int>> &nums){
        int n= nums.size();
        
        int start= indx+1;
        int end= n-1;
        
        int res= n;
        while(start<=end){
            
            int mid= end + (start-end)/2;
            
            if(nums[mid][0]<=nums[indx][1])start= mid+1;
            
            else{
                
                res= mid;
                end= mid-1;
            }
        }
        
        
        return res;
    }
    int dfs(int indx,vector<vector<int>> &offers,int n){
        
        //base case
        if(indx>=n)return 0;
        
        //recursive case
        if(dp[indx] != (-1))return dp[indx];
        
        // Principle of Inclusion-Exclusion
            
        int nextIntervalIndx= customUpperBound(indx,offers);
        
        int option1= 0 + dfs(indx+1,offers,n);
        
        int option2= offers[indx][2] + dfs(nextIntervalIndx,offers,n);
        
        
        return dp[indx]= max(option1,option2);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        int len= offers.size();
        
        sort(offers.begin(),offers.end(),comp);
        
        dp.resize(100005,-1);
        return dfs(0,offers,len);
    }
};