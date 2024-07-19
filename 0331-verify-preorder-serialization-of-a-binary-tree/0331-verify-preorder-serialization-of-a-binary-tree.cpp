class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n= preorder.length();
        
        stringstream s(preorder);
        string curr;
        
        long long nodes=1;
        
        while(getline(s,curr,',')){
            
            nodes-=1;
            
            if(nodes<0)return false;
            
            if(curr != "#")nodes+=2;
        }
        
        
        return (nodes==0);
    }
};