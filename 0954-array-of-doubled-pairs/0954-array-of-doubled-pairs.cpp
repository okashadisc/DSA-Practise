class Solution {
public:
    bool canReorderDoubled(vector<int>& nums) {
        int n= nums.size();
        
        unordered_map<int,int> freq;
        
        for(int i=0;i<n;i++)freq[nums[i]]+=1;
        
        
        long long count=0;
        sort(nums.begin(),nums.end());
        
        
        for(int i=0;i<n;i++){
            
            auto num= nums[i];
            auto doubleNum= 2*nums[i];
            
            if(freq.count(num) and freq.count(doubleNum)){
                
                freq[num]-=1;
                freq[doubleNum]-=1;
                
                if(freq[num]==0)freq.erase(freq.find(num));
                if(freq[doubleNum]==0)freq.erase(freq.find(doubleNum));
                
                count+=1;
            }
        }
        
        for(auto i:freq){
            
            auto num= i.first;
            if(freq[num])return false;
        }
        
        
        return count==n/2;
    }
};