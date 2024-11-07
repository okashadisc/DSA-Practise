class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n= nums.size();
        
        long long setBits=0;
        
        int res=0;
        
        
        for(int i=0;i<32;i++){
            
            setBits=0;
            for(int j=0;j<nums.size();j++){
                
                auto number= nums[j];
                if(number & (1<<i)){
                    
                    setBits+= 1;
                }
            }
            
            if(setBits % 3 != 0)res|= (1<<i);
        }
        
        return res;
    }
};