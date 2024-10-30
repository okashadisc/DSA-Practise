class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        
        int start=0,end=n-1;
        
        int res= (-1);
        while(start<=end){
            
           while(start<end and nums[start]==nums[start+1])start++;
            
            while(start<end and nums[end]==nums[end-1])end--;
            
            int mid= start + (end-start)/2;
            
            if(mid>0 and nums[mid]<nums[mid-1])return nums[mid];
            
            else if(nums[start]<=nums[mid] and nums[mid]>nums[end])start= mid+1;
            
            else end=mid-1;
        }
        
        
        return nums[start];
    }
};