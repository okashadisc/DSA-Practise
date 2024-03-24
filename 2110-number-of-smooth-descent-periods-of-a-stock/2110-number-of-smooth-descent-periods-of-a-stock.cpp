class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long n= prices.size();
        
        long long i=0,j=0;
        long long res=0;
        
        while(j<n){
            
            while(prices[i] != (prices[j] + (j-i))){
                
                i++;
            }
            
            res+= (j-i+1);
            
            j++;
        }
        
        return res;
    }
};