class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n= s.length();
        
        unordered_map<int,int> h;
        int mask= 0;
        
        vector<char> vowels= {'a','e','i','o','u'};
        
        int maxLen=0;
        
        h[0]= (-1);
        for(int i=0;i<n;i++){
            
            for(int j=0;j<5;j++){
                
                if(s[i]==vowels[j]){
                    
                    mask^= (1<<j);
                    break;
                }
            }
            
            // Check if the state (mask) is repeated in the past
            if(h.count(mask)){
                
                maxLen= max(maxLen,i-h[mask]);
            }
            else h[mask]= i;
        }
        
        
        return maxLen;
    }
};