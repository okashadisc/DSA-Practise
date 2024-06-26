class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n= nums.size();
        
        vector<int> left(n,1);
        vector<int> right(n,1);
        
        for(int i=1;i<n;i++){
            
            if(nums[i]<=nums[i-1]){
                
                left[i]= (1 + left[i-1]);
            }
        }
        
        //       <---(increasing)    (i)   (increasing)--->
        for(int i=n-2;i>=0;i--){
            
            if(nums[i]<=nums[i+1]){
                
                right[i]= (1 + right[i+1]);
            }
        }
        
        vector<int> ans;
        for(int i=k;i<n-k;i++){
            
            if(left[i-1]>=k and right[i+1]>=k)ans.push_back(i);
        }
        
        
        return ans;
    }
};