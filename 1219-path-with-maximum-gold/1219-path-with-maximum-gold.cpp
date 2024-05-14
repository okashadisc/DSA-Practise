class Solution {
public:
    int ans;
    // vector<vector<int>> dp;
    
    int dfs(int i,int j,vector<vector<int>> &grid,vector<vector<bool>> &visited,int n,int m){
        
        //base case
        if(i<0 or i>=n or j<0 or j>=m or visited[i][j] or !grid[i][j])return 0;
        
        //recursive case
        // if(dp[i][j] != (-1))return dp[i][j];
        
        visited[i][j]= true;
        
        int left= dfs(i,j-1,grid,visited,n,m);
        int right= dfs(i,j+1,grid,visited,n,m);
        int top= dfs(i-1,j,grid,visited,n,m);
        int bottom= dfs(i+1,j,grid,visited,n,m);
        
        visited[i][j]= false;
        
        return max({left,right,top,bottom}) + grid[i][j];
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        
        // dp.resize(n,vector<int>(m,-1));
        
        ans= 0;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                vector<vector<bool>> visited(n,vector<bool>(m,false));
                if(grid[i][j])ans= max(ans, dfs(i,j,grid,visited,n,m));
            }
        }
        
//         for(int i=0;i<n;i++){
            
//             for(int j=0;j<m;j++){
                
//                 if(dp[i][j] != (-1) )ans=max(ans,dp[i][j]);
//         }
//     }
        
        return ans;
    }
};