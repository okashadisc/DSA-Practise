class Solution {
public:
     vector<int>dx{0,1,1,1,0,-1,-1,-1};
    vector<int>dy{1,1,0,-1,-1,-1,0,1};
    
    bool isPrime(int num){
        
     if (num <= 1)
        return false;
    // Check if n=2 or n=3
    if (num == 2 || num == 3)
        return true;
    // Check whether n is divisible by 2 or 3
    if (num % 2 == 0 || num % 3 == 0)
        return false;
     
    // Check from 5 to square root of n
    // Iterate i by (i+6)
    for (int i = 5; i <= sqrt(num); i = i + 6)
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
        
     return true;
    }
    void dfs(vector<vector<int>> &grid,int num,int i,int j,int n,int m,map<int,int> &freq,int k){
        
        //base case
        if(i<0 or i>=n or j<0 or j>=m)return;
        
        //recursive case
        
        
        num= num*10 + grid[i][j];
        // if(num==19)cout<<i<<"-->"<<j<<endl;
        
        if(isPrime(num)){
            
            if(num>10)freq[num]+=1;
        }
        
        dfs(grid,num,i + dx[k],j+dy[k],n,m,freq,k);
    }
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int n= mat.size();
        int m= mat[0].size();
        
        int res= (-1);
        int maxFreq= INT_MIN;
        map<int,int> freq;
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                                
                for(int k=0;k<8;k++){
                    
                     dfs(mat,0,i,j,n,m,freq,k);
                }
            }
                
        }
        
        int mx= INT_MIN;
        for(auto i:freq){
            
            if(i.second>=mx){
                
                res= i.first;
                mx= i.second;
            }
        }
        
        return res;
       
    }
};