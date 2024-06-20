class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        
        unordered_map<int,long long> freq;
        
        for(int i=0;i<power.size();i++){
            
            freq[power[i]]+= 1;
        }
        
        int n= freq.size();
        
        vector<int> nums;
        for(auto i:freq){
            
            nums.push_back(i.first);
        }
        
        sort(nums.begin(),nums.end());
        
        vector<long long> dp(n,0);
        
        dp[0]= (long long) (freq[nums[0]]*nums[0]);
        
        for(int i=1;i<n;i++){
            
            long long damage= (long long) (freq[nums[i]]*nums[i]);
            
            long long option1= damage;
            
            if(i-1>=0 and (nums[i]-nums[i-1]>2))option1+= (dp[i-1]);
            
            else if(i-2>=0 and (nums[i]-nums[i-2]>2))option1+= (dp[i-2]);
            
            else if(i-3>=0 and (nums[i]-nums[i-3]>2))option1+= (dp[i-3]);
            
            long long option2= dp[i-1];
            
            dp[i]=max(option1,option2);
        }
        
        
        return dp[n-1];
    }
};