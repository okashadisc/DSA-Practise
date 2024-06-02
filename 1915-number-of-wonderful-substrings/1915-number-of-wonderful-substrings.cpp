class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n= word.length();
        
        unordered_map<int,long long> h;
        
        long long mask=0;
        long long count=0;
        
        h[0]= 1;
        for(int i=0;i<n;i++){
            
            auto ch= word[i];
            
            mask^= (1<<ch-97);
            
            if(h.count(mask))count+= h[mask];
            
            for(int j=0;j<10;j++){
                
                count+= (h[mask^(1<<j)]);
            }
            
            h[mask]+=1;
        }
        
        
        return count;
    }
};