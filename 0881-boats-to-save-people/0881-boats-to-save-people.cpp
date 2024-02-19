class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n= people.size();
        
        sort(people.begin(),people.end());
        
        int i=0,j=n-1;
        // [lightest        heaviest]
        
        long long count= 0;
        while(i<=j){
            
            if(people[i]+people[j]<=limit){
                
                i++;
                j--;
            }
            else{
                
                j--;
            }
            
            count+= 1;
        }
        
        
        return count;
    }
};