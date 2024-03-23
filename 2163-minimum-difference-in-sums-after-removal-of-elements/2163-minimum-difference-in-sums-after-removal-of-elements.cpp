class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        long len= nums.size();
        
        long n= len/3;
        
        vector<long> dp1(len,0);
        vector<long> dp2(len,0);
        
        priority_queue<int> left;
        priority_queue<int,vector<int>,greater<>> right;
        
        long leftSum=0;
        long rightSum=0;
        long ans= LLONG_MAX;
        
        
        // Forward -->
        
        for(int i=0;i<len-n;i++){
            
            left.push(nums[i]);
            leftSum+= nums[i];
            
            if(left.size()>n){
                
                leftSum-= left.top();
                left.pop();
            }
            
            if(left.size()==n)dp1[i]= (leftSum);
        }
        
        // <-- Backward
        
        for(int i=len-1;i>=n;i--){
            
            right.push(nums[i]);
            rightSum+= nums[i];
            
            if(right.size()>n){
                
                rightSum-= right.top();
                right.pop();
            }
            
            if(right.size()==n)dp2[i]=(rightSum);
        }
        
        
        for(int i=n-1;i<len-n;i++){
            
            ans=min(ans, dp1[i]-dp2[i+1]);
        }
        
        return ans;
    }
};