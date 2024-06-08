class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n= intervals.size();
        if(n==1)return 1;
        
        vector<int> arr;
        vector<int> dept;
        
        for(int i=0;i<n;i++){
            
            arr.push_back(intervals[i][0]);
            dept.push_back(intervals[i][1]);
        }
        
        sort(arr.begin(),arr.end());
        sort(dept.begin(),dept.end());
        
        int i=0,j=1;
        long long platforms= 1;
        long long maxPlatforms= 0;
        
        while(i<n and j<n){
            
            if(arr[j]<=dept[i]){
                
                j++;
                platforms+=1;
            }
            else if(arr[j]>dept[i]){
                
                platforms-=1;
                i++;
            }
            
            maxPlatforms=max(maxPlatforms,platforms);
        }
        
    
        return maxPlatforms;
    }
};