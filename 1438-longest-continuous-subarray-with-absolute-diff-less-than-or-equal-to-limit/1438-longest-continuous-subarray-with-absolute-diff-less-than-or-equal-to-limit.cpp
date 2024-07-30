class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n= nums.size();
        
        multiset<int> st;
        int left=0,right=0;
        int ans=0;
        
        while(right<n){
            
            st.insert(nums[right]);
            
            while(!st.empty() and *st.rbegin()-*st.begin()>limit){
                
                st.erase(st.find(nums[left]));
                left++;
            }
            
            ans=max(ans,right-left+1);
            right++;
        }
        
        return ans;
    }
};