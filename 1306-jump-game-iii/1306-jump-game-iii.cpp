class Solution {
public:
    bool canReach(vector<int>& nums, int start) {
        int n= nums.size();
        
        vector<vector<bool>> visited(2,vector<bool>(50005,false));
        
        queue<int> q;
        q.push(start);
        
        visited[0][start]= true;
        visited[1][start]= true;
        
        while(!q.empty()){
            
            auto pos= q.front();
            q.pop();
            
            if(nums[pos]==0)return true;
            auto forward= pos + nums[pos];
            auto backward= pos - nums[pos];
            
            if(forward<n and !visited[0][forward]){
                
                visited[0][forward]= true;
                q.push(forward);
            }
            if(backward>=0 and !visited[1][backward]){
                
                visited[1][backward]= true;
                q.push(backward);
            }
        }
        
        
        return false;
    }
};