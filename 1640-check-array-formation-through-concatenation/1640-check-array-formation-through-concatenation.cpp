class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        int n= arr.size();
        
        unordered_map<int,int> h;
        for(int i=0;i<pieces.size();i++){
            
            h[pieces[i][0]]= i;
        }
        
        int i=0;
        while(i<n){
            
            if(!h.count(arr[i]))return false;
            
            int indx= h[arr[i]];
            int j=0;
            while(j<pieces[indx].size()){
                
                if(arr[i] != pieces[indx][j])return false;
                
                i++;
                j++;
            }
        }
        
        
        return true;
    }
};