class Solution {
public:
    vector<bool> visited;
    bool canMeasureWater(int x, int y, int target) {
        
        vector<int> directions= {x,-x,y,-y};
        
        if(x+y == target or x== target or y==target)return true;
        
        
        int maxCapacity= (x+y);
        visited.resize(maxCapacity,false);
        
        queue<long long> q;
        
        q.push(0);
        visited[0]= true;
        
        
        while(!q.empty()){
            
            auto node= q.front();
            q.pop();
            
            if(node == target)return true;
            
            for(int k=0;k<4;k++){
                
                auto nextNode= node + directions[k];
                
                if(nextNode>=0 and nextNode<=maxCapacity and !visited[nextNode]){
                    
                    visited[nextNode]= true;
                    q.push(nextNode);
                }
            }
        }
        
        
        return false;
        
    }
};