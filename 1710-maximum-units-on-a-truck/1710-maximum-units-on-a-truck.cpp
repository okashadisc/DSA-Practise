class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b){
        
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n= boxTypes.size();
        
        sort(boxTypes.begin(),boxTypes.end(),comp);
        
        long long res=0;
        for(int i=0;i<n;i++){
            
            auto units= boxTypes[i][1];
            auto numberOfBoxes= boxTypes[i][0];
            
            if(truckSize-numberOfBoxes>=0){
                
                res+= (units*numberOfBoxes);
                truckSize-= numberOfBoxes;
            }
            else if(truckSize){
                
                res+= (units*truckSize);
                truckSize=0;
            }
            else break;
        }
        
        return res;
    }
};