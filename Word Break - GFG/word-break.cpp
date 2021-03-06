// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        int n=A.length();
        set<string>s(B.begin(),B.end());
        vector<bool>dp(n+1,false);
        dp[0]=true;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j>=0;j--)
            {
                if(dp[j]==true and s.find(A.substr(j,i-j+1)) != s.end())
                {
                    dp[i+1]=true;
                }
            }
        }
        return dp[n];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends