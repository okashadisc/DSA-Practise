class Solution {
public:
    int compress(vector<char>& chars) {
        int n= chars.size();
        
        vector<char> res;
        int count=0;
        
        for(int i=0;i<n;){
            
            count=1;
            auto curr= chars[i];
            if(i==n-1){
                
                res.push_back(chars[i]);
                i++;
                continue;
            }
            while(i+1<n and chars[i] == chars[i+1]){
                
                count+=1;
                i++;
            }
            
            // cout<<i<<endl;
            res.push_back(curr);
            if(count>1){
            auto str= to_string(count);
            
                cout<<str<<endl;
            for(int j=0;j<str.length();j++)res.push_back(str[j]);
                
            }
            
            i++;
            
        }
        
    
        
        chars.clear();
        for(int i=0;i<res.size();i++)chars.push_back(res[i]);
        
        
        return chars.size();
    }
};