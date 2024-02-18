class Solution {
public:
    int findLength(int num){
        
        string str= to_string(num);
        
        return str.length();
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n= arr1.size();
        int m= arr2.size();
        
        unordered_set<int> st;
        for(auto i:arr1){
            
            while(i){
                
                st.insert(i);
                i/=10;
            }
        }
        
        int maxLen= 0;
        
        for(auto i:arr2){
            
            while(i){
                
                if(st.find(i) != st.end()){
                    
                    auto len= findLength(i);
                    maxLen=max(maxLen,len);
                }
                
                i/=10;
            }
        }
        
        
        return maxLen;
    }
};