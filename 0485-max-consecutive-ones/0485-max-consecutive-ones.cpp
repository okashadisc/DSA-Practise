class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n= nums.size();
        
        int res=0;
        int subMax;
        
        if(nums[0]==1)subMax= 1;
        else subMax=0;
        
        for(int i=1;i<n;i++){
            
            if(nums[i-1]==1 and nums[i]==1){
                
                subMax+= 1;
            }
            else{
                
                res=max(res,subMax);
                subMax=1;
            }
        }
        
        cout<<subMax<<endl;
        if(nums[n-1]==1)res=max(res,subMax);
        
        
        return res;
    }
};