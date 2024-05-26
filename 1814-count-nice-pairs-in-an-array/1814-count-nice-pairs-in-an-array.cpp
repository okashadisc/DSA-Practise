class Solution {
public:
    int mod= 1e9 + 7;
    int countNicePairs(vector<int>& nums) {
        int n= nums.size();
        
        unordered_map<int,int> revMap;
        for(int i=0;i<n;i++){
            
            string str= to_string(nums[i]);
            
            reverse(str.begin(),str.end());
            int indx=0;
            while(str[indx] == '0')indx+=1;
            
            if(str[0]=='0' and indx==1)str.erase(0,0);
            else if(indx>0) str.erase(0,indx-1);
            
            
            int rev= stoi(str);
            
            revMap[nums[i]]= rev;
        }
        
        long long count=0;
        
        unordered_map<int,int> h;
        for(int i=0;i<n;i++){
             
                int val= (nums[i]- revMap[nums[i]]);
            
                if(h.count(val)) count= (count + h[val])%mod;
            
                h[val]= (h[val] + 1)%mod;
        }
        
        
        return count;
    }
};