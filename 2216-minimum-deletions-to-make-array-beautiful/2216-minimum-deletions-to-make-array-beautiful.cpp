class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n= nums.size();
        
        long long count=0;
        
        int i=0;
        while(i<n){
            
            while(i<n-1 and nums[i]==nums[i+1]){
                
                i++;
                count+=1;
            }
            
            // Covering only Even Indices
            i+=2;
        }
        
        long long beautifulArray= (n-count);
        if(beautifulArray & 1)count+=1;
        
        
        return count;
    }
};