class Solution {
public:
    int countPairsWithDiffLessThanOrEqualTo(int diff,vector<int> &nums,int n){
        
        int count=0;
        
        int  left=0,right=0;
        
        while(right<n){
            
            while(left<n and nums[right]-nums[left]>diff)left++;
            
            count+= right-left;
                
            right++;
        }
        
        
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n= nums.size();
        
        sort(nums.begin(),nums.end());
        
        int start= (nums[1]-nums[0]);
        for(int i=1;i<n;i++){
            
            start=min(start,nums[i]-nums[i-1]);
        }
        
        int end= (nums[n-1]-nums[0]);
        
        // Search Space --> [0      maxDifference]
        
        
        int ans= (-1);
        while(start<=end){
            
            int mid= start + (end-start)/2;
            
            if(countPairsWithDiffLessThanOrEqualTo(mid,nums,n)<k)start= (mid + 1);
            else{
                
                ans=mid;
                end= mid-1;
            }
        }
        
        
        return ans;
    }
};