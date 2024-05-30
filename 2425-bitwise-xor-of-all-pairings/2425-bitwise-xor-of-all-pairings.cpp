class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int m= nums2.size();
        
        vector<int> nums(n,0);
        
        int subRes=0;
        for(int i=0;i<m;i++){
            
            subRes^= nums2[i];
        }
        
        for(int i=0;i<n;i++){
            
            if(m & 1){
                
                nums[i]= (subRes^nums1[i]);
            }
            else{
                
                nums[i]= subRes;
            }
        }
        
        subRes=0;
        for(int i=0;i<nums.size();i++){
            
            subRes^= nums[i];
        }
        
        
        return subRes;
    }
};