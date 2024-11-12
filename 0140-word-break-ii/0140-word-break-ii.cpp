class Solution {
public:
    void palindromePartitioning(set<string> &st,vector<bool> &dp,string &s,int i,vector<string> &res,string subRes){
        
        //base case
        
        if(i==s.length()){
            
            subRes.pop_back();
            res.push_back(subRes);
        }
        //recursive case
        
        for(int j=i;j<s.length();j++){
            
            if(dp[i]){
                
                auto subStr= s.substr(i,j-i+1);
                if(st.count(subStr)){
                    
                    palindromePartitioning(st,dp,s,j+1,res,subRes + subStr + " ");
                }
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n= s.length();
        
        vector<bool> dp(n+1,false);
        dp[0]= true;
        set<string> st(wordDict.begin(),wordDict.end());
        
        
        for(int i=0;i<n;i++){
            
            for(int j=i;j>=0;j--){
                
                auto subStr= s.substr(j,i-j+1);
                if(dp[j] and st.count(subStr)){
                    
                    dp[i+1]= true;
                }
            }
        }
        
        vector<string> res;
        string subRes= "";
        
        if(dp[n]){
            
            palindromePartitioning(st,dp,s,0,res,subRes);
        }
        
        return res;
    }
};