class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n= trips.size();
        
        vector<int> prefixSum(2000,0);
        
        for(int i=0;i<n;i++){
            
            int passengers= trips[i][0];
            
            prefixSum[trips[i][1]]+= (passengers);
            prefixSum[trips[i][2]]-= (passengers);
        }
        
        for(int i=1;i<prefixSum.size();i++)prefixSum[i]+= prefixSum[i-1];
        
        for(int i=0;i<prefixSum.size();i++){
            
            if(prefixSum[i]>capacity)return false;
        }
        
        
        return true;
    }
};