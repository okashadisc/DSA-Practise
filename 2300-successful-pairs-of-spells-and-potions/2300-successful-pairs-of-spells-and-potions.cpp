class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n= spells.size();
        int m= potions.size();
        
        vector<int> ans(n,0);
        
        sort(potions.begin(),potions.end());
        
        //   Binary Search Approach
        
        for(int i=0;i<n;i++){
            
            int spell= spells[i];
            
            int start=0,end=m-1;
            int res= (-1);
            
            while(start<=end){
                
                int mid= start + (end-start)/2;
                
                 long long valid= (long long) spell*potions[mid];
                if(valid<success)start= mid+1;
                else{
                    
                    res= mid;
                    end= mid-1;
                }
            }
            
            // cout<<res<<" "<<endl;
            if(res==(-1))ans[i]=0;
            else ans[i]= (m-res);
        }
        
        
        return ans;
    }
};