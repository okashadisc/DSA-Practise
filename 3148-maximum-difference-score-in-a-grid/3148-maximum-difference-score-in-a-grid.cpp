class Solution {
public:
    vector<vector<int>> dp;
    
    int dfs(int i,int j,int n,int m,vector<vector<int>> &grid){
        
        //base case
        if(i<0 or i>=n or j<0 or j>=m)return 0;
        
        //recursive case
        if(dp[i][j] != (-1))return dp[i][j];
        
        int right=0,bottom=0;
        
        if(j+1<m)right= (grid[i][j+1] - grid[i][j]) + dfs(i,j+1,n,m,grid);
        if(i+1<n)bottom= (grid[i+1][j] - grid[i][j]) + dfs(i+1,j,n,m,grid);
        
        return dp[i][j]= max({0,bottom,right});
                                            
    }
    int maxScore(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        
        dp.resize(1005,vector<int>(1005,-1));
        
        int res= INT_MIN;
        
        // If the grid is sorted in an increasing order fashioned manner
        int increasingOrder=INT_MIN;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                res=max(res,dfs(i,j,n,m,grid));
                if(i+1<n)increasingOrder=max(increasingOrder,grid[i+1][j]-grid[i][j]);
                if(j+1<m)increasingOrder=max(increasingOrder,grid[i][j+1]-grid[i][j]);
            }
        }
        
        
        if(res==0)return increasingOrder;
        
        
        return res;
    }
};