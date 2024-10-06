class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n= nums.size();
        
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            
            freq[nums[i]]+=1;
        }
        
        unordered_map<int,int> need;
        
        for(int i=0;i<n;i++){
            
            if(freq[nums[i]]<=0)continue;
            
            if(need[nums[i]]){
                
                freq[nums[i]]-=1;
                need[nums[i]]-=1;
                
                if(!freq[nums[i]])freq.erase(freq.find(nums[i]));
                if(!need[nums[i]])need.erase(need.find(nums[i]));
                
                need[nums[i]+1]+=1;
            }
            else if(freq[nums[i]] and freq[nums[i]+1] and freq[nums[i]+2]){
                
                freq[nums[i]]-=1;
                freq[nums[i]+1]-=1;
                freq[nums[i]+2]-=1;
                
                if(!freq[nums[i]])freq.erase(freq.find(nums[i]));
                if(!freq[nums[i]+1])freq.erase(freq.find(nums[i]+1));
                if(!freq[nums[i]+2])freq.erase(freq.find(nums[i]+2));
                
                need[nums[i]+3]+=1;
            }
            else{
                
                return false;
            }
        }
        
        
        return true;
    }
};