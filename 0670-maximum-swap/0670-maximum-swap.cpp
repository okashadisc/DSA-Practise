class Solution {
public:
    int maximumSwap(int num) {
        
        auto str= to_string(num);
        int n= str.length();
        
        unordered_map<int,int> ngr;
        vector<int> dp(n,-1);
        
        for(int i=0;i<n;i++)dp[i]= i;
        
        int maxDigit= -1;
        
        for(int i=n-1;i>=0;i--){
            
            auto currDigit= str[i]-48;
            if(currDigit>maxDigit){
                
                maxDigit= currDigit;
                ngr[maxDigit]= i;
            }
            else if(currDigit<maxDigit){
                
                dp[i]= ngr[maxDigit];
            }
        }
        
        for(int i=0;i<n;i++){
            
            if(dp[i] != i){
                swap(str[i],str[dp[i]]);
                break;
            }
        }
        
        
        return stoi(str);
        
        
    }
};