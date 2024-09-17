class Solution {
public:
    int leastBricks(vector<vector<int>>& walls) {
        int n= walls.size();
        
        
        unordered_map<int,int> crossedLines;
        
        
        // Local Optimisation
        for(int i=0;i<n;i++){
            
            int length=0;
            for(int j=0;j<walls[i].size()-1;j++){
                
                length+= walls[i][j];
                crossedLines[length]+=1;
            }
        }
        
        // Global Optimisation
        
        int mergedCoincidentLineCount=0;
        for(auto i:crossedLines){
            
            auto mergedLine= i.second;
            
            mergedCoincidentLineCount=max(mergedCoincidentLineCount,mergedLine);
        }
        
        
         return (n-mergedCoincidentLineCount);
    }
};