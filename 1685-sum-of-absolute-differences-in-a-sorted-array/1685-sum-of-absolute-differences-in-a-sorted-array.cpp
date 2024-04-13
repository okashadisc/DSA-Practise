class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n= nums.size();
        
        vector<int> prefixSum;
        
        prefixSum.push_back(nums[0]);
        for(int i=1;i<n;i++){
            
            prefixSum.push_back(prefixSum.back() + nums[i]);
        }
        
        for(int i=0;i<n;i++)cout<<prefixSum[i]<<" "<<endl;
        vector<int> res(n,0);
        
        for(int i=0;i<n;i++){
            
            if(i-1>=0){
                
                res[i]= (i*nums[i]) -prefixSum[i-1] + ((prefixSum[n-1] - prefixSum[i-1]) -(n-i)*nums[i]);
            }
            else{
                
                res[i]= i*nums[i] + (prefixSum[n-1] -(n-i)*nums[i]);
            }
        }
        
        
        return res;
    }
};