class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        vector<int> nums= arr;
        int n= nums.size();
        
        unordered_map<int,int> h;
        int maxLen= 0;
        
        for(int i=0;i<n;i++){
            
            if(h.count(nums[i]-difference)){
                
                auto prevElement= nums[i]- difference;
                h[nums[i]]= (h[prevElement]+1);
                maxLen=max(maxLen,h[nums[i]]);
            }
            else{
                
                h[nums[i]] =1;
                maxLen= max(maxLen,1);
            }
        }
        
        return maxLen;
    }
};