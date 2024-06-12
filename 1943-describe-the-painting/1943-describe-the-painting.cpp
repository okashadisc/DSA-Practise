class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        int n= segments.size();
        
        map<long long,long long> nums;
        
        for(int i=0;i<n;i++){
            
            auto color= segments[i][2];
            
            nums[segments[i][0]]+= (color);
            nums[segments[i][1]]-= (color);
        }
        
        long long color= 0;
        long long prevColor= 0;
        long long prevIndx= (-1);
        
        vector<vector<long long>> ans;
        
        for(auto ele:nums){
            
            long long currIndx= ele.first;
            prevColor= color;
            
            // Accumulating the Effect
            color+= (ele.second);
            
            if(prevColor){
                
                ans.push_back({prevIndx,currIndx,prevColor});
            }
            
            prevIndx= currIndx;
        }
        
        
        return ans;
    }
};