class Solution {
public:
    vector<vector<int>> ans;
    
    bool isAtTheLower(int i,int j,int n,int m,vector<vector<int>> &grid){
        
        if(i==n-1 and j==m-1)return true;
        
        if(i==n-1 and j+1<m and grid[i][j+1]==0)return true;
        
        if(j==m-1 and i+1<n and grid[i+1][j]==0)return true;
        
        if(i+1<n and j+1<m and grid[i+1][j]==0 and grid[i][j+1]==0)return true;
        
        
        return false;
    }
    bool isAtTheUpper(int i,int j,int n,int m,vector<vector<int>> &grid){
        
        if(i-1>=0 and grid[i-1][j]==0 and j-1>=0 and grid[i][j-1]==0)return true;
        
        if(i-1>=0 and grid[i-1][j]==0 and j==0)return true;
        
        if(i==0 and j==0)return true;
        
        if(i==0 and j-1>=0 and grid[i][j-1]==0)return true;
        
        
        return false;
    }
    
    void dfs(int i,int j,int n,int m,vector<vector<int>> &grid,vector<vector<bool>> &visited,vector<int> &upper,vector<int> &lower){
        
        if(i<0 or i>=n or j<0 or j>=m or visited[i][j] or !grid[i][j])return;
        
        visited[i][j]= true;
        
        if(isAtTheUpper(i,j,n,m,grid)){
            
            // cout<<i<<" "<<j<<endl;
            upper.push_back(i);
            upper.push_back(j);
            
        }
        
        if(isAtTheLower(i,j,n,m,grid)){
            
            lower.push_back(i);
            lower.push_back(j);
        }
        
        dfs(i+1,j,n,m,grid,visited,lower,upper);
        dfs(i-1,j,n,m,grid,visited,lower,upper);
        dfs(i,j+1,n,m,grid,visited,lower,upper);
        dfs(i,j-1,n,m,grid,visited,lower,upper);
        
        
        
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n= land.size();
        int m= land[0].size();
        
        vector<vector<bool>> visited(305,vector<bool>(305,false));
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                vector<int> upper;
                vector<int> lower;
                
                if(land[i][j])dfs(i,j,n,m,land,visited,upper,lower);
                
                if(!upper.empty()){
                    
                    if(!lower.empty())upper.push_back(lower[0]);
                    if(!lower.empty())upper.push_back(lower[1]);
                    
                    ans.push_back(upper);
                    
                    upper.clear();
                    lower.clear();
                }
            }
        }
        
        
        return ans;
    }
};