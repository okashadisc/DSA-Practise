class Solution {
public:
    void dfs(int i,int j,int n,int m,vector<vector<int>> &grid1,vector<vector<int>> &grid2,bool &valid){
        
        //base case
        if(i<0 or i>=n or j<0 or j>=m or !grid2[i][j])return;
        
        //recursive case
        
        if(grid2[i][j]==1 and grid1[i][j]==0){
            valid= false;
            return;
        }
        
        grid2[i][j]= 0;
        
        dfs(i,j-1,n,m,grid1,grid2,valid);
        dfs(i,j+1,n,m,grid1,grid2,valid);
        dfs(i-1,j,n,m,grid1,grid2,valid);
        dfs(i+1,j,n,m,grid1,grid2,valid);
        
        
        
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n= grid1.size();
        int m= grid1[0].size();
        
        long long count=0;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(grid2[i][j]==1){
                    
                    bool valid= true;
                    dfs(i,j,n,m,grid1,grid2,valid);
                    
                    if(valid)count+=1;
                }
                
            }
        }
        
        
        return count;
    }
};