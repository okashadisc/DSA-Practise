class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n= messages.size();
        
        unordered_map<string,int> freq;
        
        for(int i=0;i<n;i++){
            
            int count=0;
           for(int j=0;j<messages[i].length();j++){
               
               if(messages[i][j] == ' ')count+=1;
           }
            count+=1;
            
            freq[senders[i]]+= count;
        }
        
        int mx=0;
        string res="";
        
        for(auto i:freq){
            
            if(i.second>mx){
                
                mx= i.second;
                res= i.first;
            }
            else if(mx == i.second and i.first>res)res= i.first;
        }
        
        return res;
    }
};