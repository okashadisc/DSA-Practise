typedef pair<int,int> node;
class Solution {
public:
    vector<int> topologicalSort(vector<vector<int>> &conditions,int k){
        
        unordered_map<int,vector<int>> h;
        vector<int> inDegree(k+1,0);
        
        for(int i=0;i<conditions.size();i++){
            
            h[conditions[i][0]].push_back(conditions[i][1]);
            inDegree[conditions[i][1]]+=1;
        }
        
        
        vector<int> res;
        queue<int> q;
        
        for(int i=1;i<=k;i++){
            
            if(!inDegree[i])q.push(i);
        }
        
        long long count=0;
        while(!q.empty()){
            
            int node= q.front();
            q.pop();
            count+=1;
            
            res.push_back(node);
            
            for(auto nbr:h[node]){
                
                inDegree[nbr]-=1;
                if(!inDegree[nbr])q.push(nbr);
            }
        }
        
        if(count==k) return res;
        
        
        return {};
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        
        vector<int> rowSort= topologicalSort(rowConditions,k);
        vector<int> colSort= topologicalSort(colConditions,k);
        
        if(colSort.size()==0 or rowSort.size()==0)return {};
        
        vector<node> nums(k+1);
        
        for(int i=0;i<rowSort.size();i++){
            
            nums[rowSort[i]].first= i;
        }
        
        for(int j=0;j<colSort.size();j++){
            
            nums[colSort[j]].second= j;
        }
        
        vector<vector<int>> ans(k,vector<int>(k,0));
        
        for(int i=1;i<=k;i++){
            
            ans[nums[i].first][nums[i].second]= i;
        }
        
        return ans;
    }
};