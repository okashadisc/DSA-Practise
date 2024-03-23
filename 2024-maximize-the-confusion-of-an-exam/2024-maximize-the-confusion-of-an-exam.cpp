class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n= s.length();
        
        unordered_map<char,int> freq;
        int maxLen= 0;
        
        int left=0,right=0;
        int maxFreq=0;
        
        while(right<n){
            
            freq[s[right]]+=1;
            maxFreq=max(maxFreq,freq[s[right]]);
            int windowLen= (right-left+1);
            
            int validWindow= windowLen - maxFreq;
            if(validWindow>k){
                
                freq[s[left]]-=1;
                left++;
            }
            
            maxLen=max(maxLen,right-left+1);
            
            right++;
        }
        
        return maxLen;
    }
};