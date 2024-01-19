// typedef pair<int,int> node;
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n= tasks.size();
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        
        vector<vector<int>> nums;
        for(int i=0;i<n;i++){
            
           nums.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(nums.begin(),nums.end());
        long long currTime=nums[0][0];
        
        vector<int> res;
        int i=0;
        while(i<n or !q.empty()){
            
            while(i<n and nums[i][0]<=currTime){
                
                q.push({nums[i][1],nums[i][2]});
                i++;
            }
                // if(!q.empty()){
                auto val= q.top();
                currTime+= val.first;
                res.push_back(val.second);
                q.pop();

            
            if(i<n and q.empty() and currTime< nums[i][0]){
                
                currTime= nums[i][0];
            }
            
        }
        
        return res;
        
    }
};