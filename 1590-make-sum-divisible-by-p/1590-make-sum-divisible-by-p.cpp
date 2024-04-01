class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n= nums.size();
        
        int prefixSum=0;
        int need_to_remove=0;
        
        unordered_map<int,int> h;
        
        for(int i=0;i<n;i++){
            
            need_to_remove= (need_to_remove + nums[i])%p;
        }
        
        if(need_to_remove == 0)return 0;
        
        int minLen= INT_MAX;
        h[0]= (-1);
        
        // We check if any subarray sums equals (need_to_remove)
        for(int i=0;i<n;i++){
            
            prefixSum= (prefixSum + nums[i])%p;
            
            
            int check= (prefixSum - need_to_remove + p)%p;
            if(h.count(check)) minLen= min(minLen,i- h[check]);
            
             h[prefixSum]= i;
        }
        
        
        if(minLen>=n)return (-1);
        
        return (minLen==INT_MAX?-1:minLen);
    }
};