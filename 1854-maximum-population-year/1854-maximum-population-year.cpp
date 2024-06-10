class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        
        vector<int> prefixSum(105,0);
        
        int n= prefixSum.size();
        
        for(int i=0;i<logs.size();i++){
            
            auto left= (logs[i][0]-1950);
            auto right= (logs[i][1]-1950)-1;
            
            prefixSum[left]+= (1);
            prefixSum[right+1]-= (1);
        }
        
        int maxVal= 0;
        int indx= (-1);
        
        for(int i=1;i<n;i++){
            
            prefixSum[i]+= prefixSum[i-1];
        }
        
        for(int i=0;i<n;i++){
            
            if(prefixSum[i]>maxVal){
                
                maxVal= prefixSum[i];
                indx= i;
            }
        }
        
        if(indx== (-1))return (-1);
        
        return (indx + 1950 );
    }
};