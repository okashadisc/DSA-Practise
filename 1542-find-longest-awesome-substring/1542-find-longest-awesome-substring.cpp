class Solution {
public:
    int longestAwesome(string s) {
        int n= s.length();
        
        int mask= 0;
        unordered_map<int,int> h;
        int maxLen= 0;
        
        for(int i=0;i<=1024;i++){
            
            h[i]= n;
        }
        
        h[0]= (-1);
        
        for(int i=0;i<n;i++){
            
            auto ch= s[i];
            mask^= (1<<(ch-48));
            
            if(h.count(mask))maxLen=max(maxLen,i-h[mask]);
            
            for(int j=0;j<=9;j++){
                
                maxLen=max(maxLen,i-h[mask^(1<<j)]);
            }
            
           h[mask]=min(h[mask],i);
        }
        
        
        return maxLen;
    }
};