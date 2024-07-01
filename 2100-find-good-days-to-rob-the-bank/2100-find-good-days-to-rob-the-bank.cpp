class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& nums, int k) {
        int n= nums.size();
        
        if(k==0){
            
            vector<int> ans;
            for(int i=0;i<n;i++)ans.push_back(i);
            
            return ans;
        }
        
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
            
            if(left[i]>=(k+1) and right[i]>=(k+1))ans.push_back(i);
        }
        
        
        return ans;
    }
};