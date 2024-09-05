class Solution {
public:
    vector<int> ans;
    void dfs(int i,string &num,vector<int> &dp,int n){
        
        //base case
        
      if(i>=n and dp.size()>=3){
          
          ans= dp;
          return;
      }
        
        if(i>=n)return;
        
        //recursive case
        
        for(int j=i;j<i+10;j++){
            
            auto left= num.substr(i,j-i+1);
            
            long long leftNum= stoll(left);
            
            if(leftNum > INT_MAX)return;
            int size= dp.size();
            
            if(j==i and num[j]=='0'){
                
                 if(dp.size()>=2 and (long long)dp[size-1] + (long long)dp[size-2] == leftNum){
                
                dp.push_back(leftNum);
                dfs(j+1,num,dp,n);
                dp.pop_back();
            }
            
            if(dp.size()<2){
                
                dp.push_back(leftNum);
                dfs(j+1,num,dp,n);
                dp.pop_back();
                }
                
                break;
            }
            if(dp.size()<2){
                
                dp.push_back(leftNum);
                dfs(j+1,num,dp,n);
                dp.pop_back();
            }
            
            if(dp.size()>=2 and (long long)dp[size-1] + (long long)dp[size-2] == leftNum){
                
                dp.push_back(leftNum);
                dfs(j+1,num,dp,n);
                dp.pop_back();
            }
            
            
        }
            
           
    }
    vector<int> splitIntoFibonacci(string num) {
        // if(num[0]=='0')return {};
        
        int n= num.length();
        
        vector<int> dp;
        dfs(0,num,dp,n);
        
        
        return ans;
    }
};