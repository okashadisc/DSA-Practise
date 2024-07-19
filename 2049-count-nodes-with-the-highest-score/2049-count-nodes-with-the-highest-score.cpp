class Solution {
public:
    vector<int> subTreeSize;
    unordered_map<int,vector<int>> h;
    
    int dfs(int node){
        
        int count=1;
        
        for(auto nbr:h[node]){
            
            count+= dfs(nbr);
        }
        
        return subTreeSize[node]= count;
    }
    int countHighestScoreNodes(vector<int>& parents) {
        int n= parents.size();
        
        for(int i=0;i<n;i++)h[parents[i]].push_back(i);
        
        subTreeSize.resize(n,1);
        
        dfs(0);
        
        long long maxScore= LLONG_MIN;
        long long res=0;
        
        for(int node=0;node<n;node++){
            
            long long score=1;
            
            score=max(score,(long long)n-subTreeSize[node]);
            
            for(auto child:h[node]){
                
                score= score*(subTreeSize[child]);
            }
            
            if(score>maxScore){
                res=1;
                maxScore= score;
            }
            else if(maxScore==score)res+=1;
        }
        
        
        return res;
    }
};