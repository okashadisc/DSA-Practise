class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n= nums.size();
        
        unordered_set<int> st(nums.begin(),nums.end());
        
        if(st.count(original)){
            
            while(st.count(original)){
                
                auto newVal= original*2;
                original= newVal;
            }
        }
        
        
        return original;
    }
};