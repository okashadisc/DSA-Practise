class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n= nums.size();
        
        stack<int> st;
        
        //creating a monotonic stack
        for(int i=0;i<n;i++){
            
            if(st.empty() or nums[i]<nums[st.top()]){
                
                st.push(i);
            }
        }
        
        //Greedy --> Try from back
        
        int maxLen= 0;
        for(int j=n-1;j>=0;j--){
            
            while(!st.empty() and nums[j]>=nums[st.top()]){
                
                auto i= st.top();
                maxLen=max(maxLen,j-i);
                st.pop();
            }
        }
        
        
        return maxLen;
    }
};