class Solution {
public:
    int numSplits(string s) {
        int n= s.length();
        
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        
        unordered_map<char,int> freq;
        for(int i=0;i<n;i++){
            
            freq[s[i]]+=1;
            prefix[i]= freq.size();
        }
        
        freq.clear();
        for(int i=n-1;i>=0;i--){
            
            freq[s[i]]+= 1;
            suffix[i]= freq.size();
        }
        
        long long count=0;
        for(int i=0;i<n-1;i++){
            
            if(prefix[i] == suffix[i+1])count+=1;
        }
        
        return count;
    }
};