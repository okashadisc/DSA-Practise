class Solution {
public:
    bool utility(int row,int col,int n,int m,vector<vector<int>> &grid){
        
        set<int> st;
        long long sum=0;
        if(row+2>=n)return false;
        if(col+2>=m)return false;
        
        for(int i=row;i<row+3;i++){
            
            for(int j=col;j<col+3;j++){
                
                if(grid[i][j]>=1 and grid[i][j]<=9)st.insert(grid[i][j]);
            }
        }
        
        if(st.size() != 9)return false;
        
        
        sum+= grid[row][col];
        sum+= grid[row+1][col+1];
        sum+= grid[row+2][col+2];
        
        long long newSum=0;
        for(int i=row;i<row+3;i++){
            
            for(int j=col;j<col+3;j++)newSum+= grid[i][j];
            
            if(newSum != sum)return false;
            newSum=0;
        }
        
        newSum=0;
        for(int j=col;j<col+3;j++){
            
            for(int i=row;i<row+3;i++){
                
                newSum+= grid[i][j];
            }
            
            if(newSum != sum)return false;
            newSum=0;
        }
        
        newSum=0;
        // cout<<sum<<endl;

        newSum+= grid[row][col+2];
        newSum+= grid[row+1][col+1];
        newSum+= grid[row+2][col];
        
        if(newSum != sum)return false;
        
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        
        long long count=0;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(utility(i,j,n,m,grid))count+=1;
            }
        }
        
        
        return count;
    }
};