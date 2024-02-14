class Solution {
public:
    vector<vector<vector<int>>> dp;
    int dfs(int x1,int y1,int y2,vector<vector<int>> &grid,int n){
        
        //base case
        int x2= x1 + y1 - y2;
        if(x1>=n or x2>=n or y1>=n or y2>=n or grid[x1][y1]==(-1) or grid[x2][y2]==(-1))return INT_MIN;

        
        //recursive case
        if(dp[x1][y1][y2] != (-1))return dp[x1][y1][y2];
        
        int ans=0;
        if(x1==n-1 and y1==n-1)return grid[x1][y1];
        
        if(x1==x2 and y1==y2)ans+= grid[x1][y1];
        else ans+= (grid[x1][y1] + grid[x2][y2]);
        
                                                 // (path1,path2)
        
        int option1= dfs(x1+1,y1,y2,grid,n);     // (down,down)
        int option2= dfs(x1,y1+1,y2,grid,n);     // (right,down)
        int option3= dfs(x1+1,y1,y2+1,grid,n);   // (down,right)
        int option4= dfs(x1,y1+1,y2+1,grid,n);   // (right,right)
        
        return dp[x1][y1][y2]= max({option1,option2,option3,option4}) + ans;
  
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n= grid.size();
        
        dp.resize(55,vector<vector<int>>(55,vector<int>(55,-1)));
        return max(0,dfs(0,0,0,grid,n));
    }
};