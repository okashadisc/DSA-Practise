class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n= nums.size();
        
        int minIndx= (-1);
        int maxIndx= (-1);
        
        int startIndx=0;
        
        long long count=0;
        
        for(int i=0;i<n;i++){
            
            // Fresh Start
            
            if(nums[i]>maxK or nums[i]<minK){
                
                minIndx= i;
                maxIndx= i;
                
                startIndx= (i+1);
            }
            
            if(nums[i]==minK)minIndx= (i);
            
            if(nums[i]==maxK)maxIndx= (i);
            
            //     totalSubarrays     A= (B) -  (C)
            count+= (i-startIndx+1) - ( (i+1) - (min(minIndx,maxIndx)+1) );
        }
        
        return count;
    }
};