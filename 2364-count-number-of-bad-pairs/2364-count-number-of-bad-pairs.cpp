class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n= nums.size();
        
        unordered_map<int,int> h;
        long long count= 0;
        
        for(int i=0;i<n;i++){
            
            auto val= (nums[i]-i);
            
            if(h.count(val))count+= h[val];
            
            h[val]+=1;
        }
        
        // unsigned long long totalPairs= (long long)(n*(n-1))/2;
        
        return  1L*n*(n-1)/2 - count;
    }
};