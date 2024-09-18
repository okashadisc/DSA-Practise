class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n= seats.size();
        
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        // vector<bool> presentOnLeft(n,false);
        // vector<bool> presentOnRight(n,false);
        
        long long dist=0;
        
        left[0]=0;
        for(int i=1;i<n;i++){
            
            if(seats[i]==1){
                
                left[i]=0;
                dist=0;
            }
            else{
                
                dist+=1;
                left[i]= dist;
            }
        }
        
        dist=0;
        right[n-1]=0;
        for(int i=n-2;i>=0;i--){
            
            if(seats[i]==1){
                
                right[i]=0;
                dist=0;
            }
            else{
                
                dist+=1;
                right[i]= dist;
            }
        }
        
        int ans= INT_MIN;
        
        for(int i=0;i<n;i++){
            
            if(i==0 and !seats[i]){
                
                int possibleAns= right[i];
                ans=max(ans,possibleAns);
                continue;
            }
            
            if(i==n-1 and !seats[i]){
                
                int possibleAns= left[i];
                ans=max(ans,possibleAns);
                continue;
            }
            if(!seats[i]){
                
                int possibleAns= min(left[i],right[i]);
                ans=max(ans,possibleAns);
            }
        }
        
        
        return ans;
    }
};