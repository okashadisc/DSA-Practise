class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n= nums.size();
        
        long long maxSteps= 0;
        unordered_set<int> visited;
        
        for(int i=0;i<n;i++){
            
            if(!visited.count(nums[i])){
                
                long long steps=0;
                int current= nums[i];
                while(!visited.count(current)){
                    
                    // cout<<current<<" ";
                    visited.insert(current);
                    if(nums[current]<n)current= nums[current];
                    steps+=1;
                }
                
                // cout<<endl;
                maxSteps=max(maxSteps,steps);
            }
        }
        
        
        return maxSteps;
    }
};