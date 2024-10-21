static vector<int> spf;
static bool flag= true;
class Solution {
public:
    
     int greatestPositiveDivisor(int x) {
        if (x == 1) return 1; 
        return x / spf[x];
    }
    
    // Pre-Coumputation of SmallestPrimeFactor
    void sieveOfEratosthenes(int n){
        
        spf.resize(n+1);
        for(int i=0;i<=n;i++){
            
            spf[i]= i;
        }
        
        for(int i=2;i*i<=n;i++){
            
            if(spf[i]==i){
                
                for(int j=2*i;j<=n;j+=i){
                    
                    if(spf[j] == j)spf[j]= i;
                }
            }
        }
    }
    int minOperations(vector<int>& nums) {
        int n= nums.size();
        
        int size= (1e6);
        
        if(flag){
        sieveOfEratosthenes(1e6);
            flag= false;
        }
        
        long long count=0;
        for(int i=n-2;i>=0;i--){
            
            while(nums[i]>nums[i+1]){
                
                int gpd= greatestPositiveDivisor(nums[i]);
                
                if(gpd == 1)return (-1);
                
                nums[i]= nums[i]/gpd;
                count+=1;
                
                if(nums[i]==1 and nums[i]>nums[i+1])return (-1);
            }
        }
        
        
        return count;
    }
};