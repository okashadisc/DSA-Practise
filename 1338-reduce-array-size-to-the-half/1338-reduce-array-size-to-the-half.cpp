class Solution {
public:
    int minSetSize(vector<int>& nums) {
        int n= nums.size();
        
        unordered_map<int,int> freq;
        
        for(int i=0;i<n;i++){
            
            freq[nums[i]]+=1;
        }
        
        priority_queue<int> q;
        for(auto i:freq){
            
            q.push(i.second);
        }
        
        long long steps=0;
        
        long long removed= 0;
        while(removed*2 < n){
            
            removed+= q.top();
            q.pop();
            
            steps+= 1;
        }
        
        return steps;
    }
};