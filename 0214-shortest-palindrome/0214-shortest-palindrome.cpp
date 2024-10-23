class Solution {
public:
    vector<int> KMP(string &pattern){
        
        // Applying KMP-Algorithm
        vector<int> lps(pattern.length(),0);
        
        // Devising a 2-pointer Approach
        
        int prevIndx=0,i=1;
        
        for(int i=1;i<pattern.length();){
            
            if(pattern[prevIndx] == pattern[i]){
                
                lps[i]= prevIndx + 1;
                i++;
                prevIndx++;
            }
            
            else{
                
                if(prevIndx != 0){
                    
                    prevIndx= lps[prevIndx-1];
                }
                else{
                    
                    lps[i]=0;
                    i++;
                }
            }
        }
        
        return lps;
    }
    string shortestPalindrome(string s) {
        int n= s.length();
        
        string newString= s;
        reverse(newString.begin(),newString.end());
        
        string pattern= s + "#" + newString;
        
        vector<int> lookUpTable= KMP(pattern);
        
        auto resultant= s.substr(lookUpTable[lookUpTable.size()-1]);
        reverse(resultant.begin(),resultant.end());
        
        resultant= resultant + s;
        
        
        return resultant;
        
    }
};