class Solution {
public:
    int dfs(int indx,vector<int> &nums,int n,int mask){
        
        //base case
        if(indx>n)return 1;
        
        //recursive case
        
        long long count=0;
        for(int i=0;i<nums.size();i++){
            
            if(nums[i] % indx == 0 or indx % nums[i] == 0){
                
                if((mask & (1<<i)) == 0){
                    
                    mask|= (1<<i);
                    count+= dfs(indx+1,nums,n,mask);
                    mask&= ~(1<<i);
                }
            }
        }
        
        
        return count;
    }
    int countArrangement(int n) {
        
        vector<int> nums;
        for(int i=1;i<=n;i++)nums.push_back(i);
        
        return dfs(1,nums,n,0);
    }
};