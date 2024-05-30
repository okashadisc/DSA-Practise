class Solution {
public:
    int max= INT_MIN;
    int count=0;
    
    void dfs(int i,vector<int> &subRes,vector<int> &nums,int n){
        
        //base case
        if(i>=n){
            
            int ans=0;
            for(int j=0;j<subRes.size();j++){
                
                ans|= subRes[j];
            }
            
            if(ans>max){
                
                max= ans;
                count=1;
            }
            else  if(ans==max)count+= 1;
            
            return;
        }
        
        //recursive case
        
        subRes.push_back(nums[i]);
        dfs(i+1,subRes,nums,n);
        subRes.pop_back();
        
        dfs(i+1,subRes,nums,n);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n= nums.size();
        
        vector<int> subRes;
        dfs(0,subRes,nums,n);
        
        return count;
    }
};