class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n= nums.size();
        
        int maxOperations= INT_MIN;
        int left=0,right=0;
        long long sum=0;
        long long totalSum=0;
        
        for(int i=0;i<n;i++)totalSum+= nums[i];
        
        if(totalSum == x)return (n);
        // sum+= nums[0];
        while(right<n){
            
            sum+= nums[right];
            while(totalSum-sum<x and left<right){
                
                sum-= nums[left];
                left++;
            }
            
            if(totalSum-sum==x)maxOperations=max(maxOperations,right-left+1);
            right++;
        }
        
        
        if(maxOperations == INT_MIN)return (-1);
        return (n-maxOperations);
    }
};