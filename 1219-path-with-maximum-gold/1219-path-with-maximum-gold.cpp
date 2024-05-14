class Solution {
public:
    int ans;
    // vector<vector<int>> dp;
    
    void dfs(int i,int j,vector<vector<int>> &grid,vector<vector<bool>> &visited,int n,int m,int gold){
        
        //base case
        if(i<0 or i>=n or j<0 or j>=m or visited[i][j] or !grid[i][j])return;
        
        //recursive case
        // if(dp[i][j] != (-1))return dp[i][j];
        
        visited[i][j]= true;
        
        gold+= grid[i][j];
        ans= max(ans,gold);
        
        
        dfs(i,j-1,grid,visited,n,m,gold);
        dfs(i,j+1,grid,visited,n,m,gold);
        dfs(i-1,j,grid,visited,n,m,gold);
        dfs(i+1,j,grid,visited,n,m,gold);
        
        visited[i][j]= false;
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        
        // dp.resize(n,vector<int>(m,-1));
        
        ans= 0;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                vector<vector<bool>> visited(n,vector<bool>(m,false));
                if(grid[i][j])dfs(i,j,grid,visited,n,m,0);
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