typedef pair<int,pair<int,int>> node;
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n= grid.size();
        int m= grid[0].size();
        
        priority_queue<node,vector<node>,greater<node>> q;
        
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
        visited[0][0]= true;
        q.push({grid[0][0],{0,0}});
        
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        
        
        vector<int> path;
        
        
        while(!q.empty()){
            
            auto node= q.top();
            q.pop();
            
            path.push_back(node.first);
            auto curx= node.second.first;
            auto cury= node.second.second;
            
            for(int k=0;k<4;k++){
                
                auto x= curx + dx[k];
                auto y= cury + dy[k];
                
                if(x>=0 and x<n and y>=0 and y<m and !visited[x][y]){
                    
                    visited[x][y]= true;
                    q.push({grid[x][y],{x,y}});
                }
            }
        }
        
        // for(int i=0;i<path.size();i++)cout<<path[i]<<" ";
        // cout<<endl;
        
        vector<int> temp= queries;
        
        sort(temp.begin(),temp.end());
        
        unordered_map<int,long long> sol;
        
        long long count=0;
        int i=0;
        
        for(int j=0;i<temp.size() and j<path.size();){
            
            if(temp[i]>path[j]){
                count+=1;
                
                if(j == path.size()-1)sol[temp[i]]= count;
                j++;
            }
            
            else{
                
                sol[temp[i]]= count;
                i++;
            }
        }
        
        
        while(i<temp.size()){
            
            sol[temp[i]]= count;
            i++;
        }
        
        
        
        vector<int> ans;
        
        for(int i=0;i<queries.size();i++){
            
            ans.push_back(sol[queries[i]]);
        }
        
        
        return ans;
    }
};