class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n= nums.size();
        
        vector<long long> prefixSum;
        prefixSum.push_back(nums[0]);
        
        for(int i=1;i<n;i++){
            
            prefixSum.push_back(prefixSum.back() + nums[i]);
        }
        
        long long int ans= INT_MAX;
        int indx= (-1);
        
        for(int i=0;i<n;i++){
            
            long long left= (prefixSum[i])/(i+1);
            long long right=0;
            
            if(i<n-1){
                
            right= (prefixSum[n-1]-prefixSum[i])/(n-i-1);
                
            }
            
            if(abs(left-right)<ans){
                ans=min(ans,abs(left-right));
                indx=i;
            }
            
        }
        
      return indx;
    }
};