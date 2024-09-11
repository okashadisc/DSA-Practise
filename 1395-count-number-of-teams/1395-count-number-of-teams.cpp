class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n= rating.size();
        
        vector<int> dp(n,0);
        
        int count=0;
        for(int i=0;i<n;i++){
            
            for(int j=i-1;j>=0;j--){
                
                if(rating[j]<rating[i]){
                    
                    // This could form a potential LIS of (3) elements
                    
                    dp[i]+=1;
                    count+= dp[j];
                }
            }
        }
        
        dp.assign(n,0);
        
        for(int i=0;i<n;i++){
            
            for(int j=i-1;j>=0;j--){
                
                if(rating[j]>rating[i]){
                    
                    dp[i]+=1;
                    count+= dp[j];
                }
            }
        }
        
        
        return count;
        
    }
};