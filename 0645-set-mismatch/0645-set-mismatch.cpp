class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n= nums.size();
        
        multiset<int> st(nums.begin(),nums.end());
        
        vector<int> res(2,0);
        
        for(int i=1;i<=n;i++){
            
            if(st.count(i)>1)res[0]= i;
            
            else if(!st.count(i))res[1]= i;
        }
        
        
        return res;
    }
};