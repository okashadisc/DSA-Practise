class Solution {
public:
    long long mod= 1e9 + 7;
    long long sumToN(long long n){
        
        return (long long) (n*(n+1))/2;
    }
    int maxProfit(vector<int>& inventory, int orders) {
        int n= inventory.size();
        
        sort(inventory.begin(),inventory.end());
        
        long long res=0;
        for(int i=n-1;i>=0;i--){
            
            long long diff;
            if(i==0)diff= inventory[i];
            else diff= inventory[i]-inventory[i-1];
            
            int width= (n-i);
            long long area= min((long long)orders,diff*width);
            
            long long r= inventory[i];
            long long l= r - area/(width);
            
            long long sum= (sumToN(r) - sumToN(l));
            long long profit= sum*width;
            
            res+= profit;
            res%= mod;
            
            profit= l*(area%width);
            res+= profit;
            res%= mod;
            
            orders-= area;
        }
        
        return res;
    }
};