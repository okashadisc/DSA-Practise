class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n= nums.size();
        
        long long F=0, allSum=0;
        for(int i=0;i<n;i++){
            
            // Pre-computation of f(0) --> (Zero) rotations
            F+= i*(nums[i]);
            allSum+= nums[i];
        }
        
        long long res= F;
        for(int i=n-1;i>=1;i--){
            
           //F(k)= F(k-1) + allSum - n*Bk[0];
            
            F= F + allSum - n*nums[i];
            res=max(res,F);
        }
        
        
        return res;
    }
};