class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n= nums.size();
        
        vector<int> prefixSum(n+1,0);
        
        for(int i=0;i<queries.size();i++){
            
            auto left= queries[i][0];
            auto right= queries[i][1];
            
            prefixSum[left]-=1;
            
            prefixSum[right+1]+=1;
        }
        
        // Keep Accumulating the Effects
        for(int i=1;i<prefixSum.size();i++){
            
            prefixSum[i]+= prefixSum[i-1];
        }
        
        for(int i=0;i<n;i++){
            
            nums[i]+= prefixSum[i];
        }
        
        
        // Final Check Through the whole (nums)
        
        for(int i=0;i<n;i++){
            
            if(nums[i]>0)return false;
        }
        
        
        return true;
    }
};