class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n= nums.size();
        
        long long int maxLen=1;
        long long int i=0;
        int j=0;
        long long int sum=0;
        
        sort(nums.begin(),nums.end());
        
        while(j<n){
            
            sum+= nums[j];
            while((j-i+1)*nums[j] - sum > k){
                
                sum-= nums[i];
                i++;
            }
            
            maxLen=max(maxLen,j-i+1);
            j++;
        }
        
        return maxLen;
    }
};