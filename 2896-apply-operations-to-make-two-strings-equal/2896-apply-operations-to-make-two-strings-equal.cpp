class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int i,int j,vector<int> &indices,int x){
        int n= indices.size();
        
        
        //base case
        if(i>=n)return 0;
        
        if(j<0)return 0;
        if(i>j)return 0;
        
        //recursive case
        if(dp[i][j] != (-1))return dp[i][j];
        
        int option1= (indices[i+1]-indices[i]) + dfs(i+2,j,indices,x);
        
        int option2= (indices[j]-indices[j-1]) + dfs(i,j-2,indices,x);
        
        int option3= x + dfs(i+1,j-1,indices,x);
        
        
        return dp[i][j]= min({option1,option2,option3});
    }
    int minOperations(string s1, string s2, int x) {
        int n= s1.length();
        
        vector<int> indices;
        for(int i=0;i<n;i++){
            
            if(s1[i] != s2[i])indices.push_back(i);
        }
        
        if(indices.size() % 2 != 0)return (-1);
        
        dp.resize(505,vector<int>(505,-1));
        return dfs(0,indices.size()-1,indices,x);
    }
};