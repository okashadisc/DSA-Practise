typedef pair<int,pair<int,int>> node;
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        
        if(grid[0][1]>1 and grid[1][0]>1)return (-1);
        
        
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
        priority_queue<node,vector<node>,greater<node>> q;
        
        q.push({0,{0,0}});
        visited[0][0]= true;
        
        int dx[4]= {1,-1,0,0};
        int dy[4]= {0,0,1,-1};
        
        
        // At every point, we pick up the node with the minimumAccessTime
        // And traverse further through this (node)
        
        
        while(!q.empty()){
            
            auto val= q.top();
            q.pop();
            
            auto curx= val.second.first;
            auto cury= val.second.second;
            auto time= val.first;
            
            if(curx==n-1 and cury==m-1)return time;
            
            for(int k=0;k<4;k++){
                
                auto x= curx + dx[k];
                auto y= cury + dy[k];
                
                if(x>=0 and x<n and y>=0 and y<m and !visited[x][y]){
                    
                    visited[x][y]= true;
                    
                    int wait= (grid[x][y]-time) % 2 == 0;
                    auto newTime= max(grid[x][y] + wait,time+1);
                    
                    q.push({newTime,{x,y}});
                }
            }
        }
        
        
        return (-1);
    }
};