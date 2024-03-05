class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n= piles.size();
        
        long long ans=0;
        
        sort(piles.begin(),piles.end());
        
        //   SSS ML ML ML
        
        for(int i=n/3;i<n;i+=2){
            
            ans+= piles[i];
        }
        
        
        return ans;
    }
};