typedef pair<int,int> node;
class Solution {
public:
    static bool comp(node &a,node &b){
        
        if(a.second == b.second){
            
            return a.first>b.first;
        }
        
        return a.second<b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        int n= nums.size();
        
        unordered_map<int,int> freq;
        
        for(int i=0;i<n;i++){
            
            freq[nums[i]]+= 1;
        }
        
        sort(nums.begin(),nums.end(),[&](int a,int b){
            
            if(freq[a] == freq[b])return a>b;
            return freq[a]<freq[b];
        });
        
        return nums;
    }
};