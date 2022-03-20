class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int a=(-1),b=(-1);
        int curr_len=0;
        int max_len=0;
        int b_count=0;
        
        for(int i=0;i<n;i++){
            int c=fruits[i];
            if(c==a or c==b){
                curr_len+=1;
            }
            else{
                curr_len=b_count+1;
            }
            
            if(c==b){
                b_count+=1;
            }
            else{
                b_count=1;
            }
            
            if(c!=b){
                a=b;
                b=c;
            }
            
            max_len=max(max_len,curr_len);
        }
        
        return max_len;
        
    }
};