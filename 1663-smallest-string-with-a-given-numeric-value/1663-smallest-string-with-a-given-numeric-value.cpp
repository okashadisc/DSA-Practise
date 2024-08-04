class Solution {
public:
    string getSmallestString(int n, int k) {
        
        string res(n,'a');
        
        k-=(n);
        
        for(int i=res.length()-1;i>=0;i--){
            
            
            if(k>=25){
                
                res[i]= (122);
                k-= (25);
            }
            else{
                
                res[i]= (97+k);
                k=0;
                break;
            }
        }
        
        
        return res;
    }
};