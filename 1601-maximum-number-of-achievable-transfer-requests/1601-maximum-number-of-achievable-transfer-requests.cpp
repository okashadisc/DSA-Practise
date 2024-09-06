class Solution {
public:
    int res;
    vector<int> count;
        void dfs(int indx,int n,vector<vector<int>> &requests,int numberOfCurrentRequests){
        
        //base case
        if(indx>=requests.size()){
            
            for(int i=0;i<n;i++){
                
                if(count[i] != 0)return;
            }
            
            res=max(res,numberOfCurrentRequests);
            return;
        }
        
        //recursive case
        
        // Apply Principle of Inclusion-Exclusion
        
        // Once I will Include
        
        count[requests[indx][0]]-=1;;
        count[requests[indx][1]]+=1;
        
        dfs(indx+1,n,requests,numberOfCurrentRequests+1);
        
        count[requests[indx][0]]+=1;
        count[requests[indx][1]]-=1;
        
        // Once I will exclude
        
        dfs(indx+1,n,requests,numberOfCurrentRequests);
        
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        
        count.resize(n,0);
        
        res=0;
        dfs(0,n,requests,0);
        
        return res;
    }
};