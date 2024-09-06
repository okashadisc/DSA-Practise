class Solution {
public:
    long long res;
        int dfs(int indx,int n,vector<vector<int>> &requests,vector<int> &count){
        
        //base case
        if(indx==requests.size()){
            
            for(int i=0;i<n;i++){
                
                if(count[i] != 0)return INT_MIN;
            }
            return 0;
        }
        
        //recursive case
        
        // Apply Principle of Inclusion-Exclusion
        
        // Once I will Exclude
        
            
        int option2= 0 + dfs(indx+1,n,requests,count);
        
        // Once I will Include
        count[requests[indx][0]]-=1;;
        count[requests[indx][1]]+=1;
        
        int option1= 1 +  dfs(indx+1,n,requests,count);
            
        
        count[requests[indx][0]]+=1;
        count[requests[indx][1]]-=1;
        
        return max(option1,option2);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        
        vector<int> count;
        count.resize(n,0);
        
        res=0;
        return dfs(0,n,requests,count);
        
    }
};