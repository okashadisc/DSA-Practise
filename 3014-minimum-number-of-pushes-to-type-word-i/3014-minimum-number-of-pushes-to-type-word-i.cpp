class Solution {
public:
    int minimumPushes(string word) {
        int n= word.length();
        
        if(n<=8)return n;
        
        if(n>8 and n<=16)return 8 + (n-8)*2;
        
        if(n>16 and n<=24)return 24 + (n-16)*3;
        
        return 48 + (n-24)*4;
    }
};