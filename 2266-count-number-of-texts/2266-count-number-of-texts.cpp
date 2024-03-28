class Solution {
public:
    const int mod= 1e9 + 7;
    int countTexts(string pressedKeys) {
        int n= pressedKeys.length();
        
        vector<int> dp(n+1,0);
        
        dp[0]= 1;
        dp[1]= 1;
        
        for(int i=2;i<=n;i++){
            
            dp[i]= dp[i-1]%mod;     //  --> opt1
            
            if(i-2>=0 and pressedKeys[i-1]==pressedKeys[i-2]){ 
                
                dp[i]= (dp[i] + dp[i-2])%mod;     // -->  opt2
                
                if(i-3>=0 and pressedKeys[i-1]==pressedKeys[i-3]){
                    
                    dp[i]= (dp[i] + dp[i-3])%mod;    // --> opt3
                    
                    if((pressedKeys[i-1]=='7' or pressedKeys[i-1]=='9') and i-4>=0 and pressedKeys[i-1]==pressedKeys[i-4]){
                        
                        dp[i]= (dp[i] + dp[i-4])%mod;   // --> opt4
                    }
                }
            }
        }
        
        
        return dp[n];
    }
};