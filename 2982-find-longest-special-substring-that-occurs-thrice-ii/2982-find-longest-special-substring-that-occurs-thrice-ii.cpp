class Solution {
public:
    int maximumLength(string s) {
        int n= s.length();
        
        unordered_map<string,int> h;
        
        int j=0;
        string temp= "";
        temp+= s[j];
        for(int i=1;i<n;i++){
            
            if(s[i]==s[j])temp+= s[i];
            else{
                
                h[temp]+=1;
                j= i;
                temp="";
                temp+= s[i];
            }
        }
        
        h[temp]+= 1;
        
        int maxLen= 0;
        for(auto i:h){
            
            cout<<i.first<<"-->"<<i.second<<endl;
            string temp= i.first;
            int freq= i.second;
            int len= temp.length();
            
            if(freq>=3)maxLen=max(maxLen,len);
            else if(freq==2){
                
                if(temp.length()-1 > 0)maxLen=max(maxLen,len-1);
            }
            else if(len>1 and h.count(temp.substr(0,len-1))){
                
                if(temp.length()-1 > 0)maxLen=max(maxLen,len-1);
            }
            else{
                
                if(temp.length()-1 > 0)maxLen=max(maxLen,len-2);
            }
        }
        
        
        return (maxLen==0?-1:maxLen);
    }
};