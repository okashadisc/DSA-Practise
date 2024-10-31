class Solution {
public:
    int isValid(vector<int> &nums,int n){
        
        for(int i=0;i<n-1;i++){
            
            
            if(nums[i]>nums[i+1])return (i);
        }
        
        
        return (-1);
    }
    bool checkPossibility(vector<int>& nums) {
        int n= nums.size();
        
        auto errorIndx= isValid(nums,n);
        
        if(errorIndx == (-1))return true;
        
        auto errorValue= nums[errorIndx];
        
        nums[errorIndx]= nums[errorIndx+1];
        if(isValid(nums,n) == (-1))return true;
        
        nums[errorIndx]= errorValue;
        nums[errorIndx+1]= nums[errorIndx];
        
        if(isValid(nums,n) == (-1))return true;
        
        
        return false;
        
        
    }
};