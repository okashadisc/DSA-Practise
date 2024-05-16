class DSU {
public:
    vector<int> rank;
    vector<int> parent;
    
    DSU(int n){
        
        rank.resize(100005,1);
        parent.resize(100005,0);
        
        for(int i=1;i<=n;i++){
            
            parent[i]= i;
        }
    }
    
    int findPar(int node){
        if(node==parent[node])return node;
        
        return parent[node]= findPar(parent[node]);
    }
    
    void Union(int u,int v){
        
        u= findPar(u);
        v= findPar(v);
        
        if(u==v)return;
        
        if(rank[u]<rank[v]){
            
            rank[v]+= rank[u];
            parent[u]= v;
        }
        else {
            
            rank[u]+= rank[v];
            parent[v]= u;
        }
        
        
    }
};
class Solution {
public:
    vector<int> sievePrimeFactorization(int n){
        
        vector<int> primes(100005,0);
        
        for(int i=2;i<=n;i++)primes[i]= i;
        
        for(int i=2;i<=n;i++){
            
            if(primes[i]==i){
                
                for(int j=2*i;j<=n;j+=i){
                    
                    if(primes[j]==j)primes[j]= i;
                }
            }
        }
        
        return primes;
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int n= nums.size();
        if(n==1)return true;
        
        int maxElement= (-1);
        
        for(int i=0;i<n;i++){
            
            if(nums[i]==1)return false;
            maxElement=max(maxElement,nums[i]);
        }
        
        
        
        auto primes= sievePrimeFactorization(maxElement);
        
        DSU ds(maxElement);
        
        
        // Each time you pick up a (number) and do the primefactorization of the (number)
        // and we keep joing the (number) and its primeFactor
        
        
        for(int i=0;i<n;i++){
            
            auto num= nums[i];
            
            while(num>1){
                
            int primeFactor= primes[num];
            
            ds.Union(nums[i],primeFactor);
            
                while(num % primeFactor==0){
                
                    num/=(primeFactor);
                }
                
            }
        }
        
        int parentNode= ds.findPar(nums[0]);
        
        for(int i=1;i<n;i++){
            
            if(ds.findPar(nums[i]) != parentNode)return false;
        }
        
        
        return true;
        
    }
};