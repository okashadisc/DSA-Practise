class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len= flowerbed.size();
        
        int count=0;
        for(int i=0;i<len;i++){
            
            if(flowerbed[i]==0){
                
                if((i==0 or flowerbed[i-1]==0) and (i==len-1 or flowerbed[i+1]==0)){
                    
                    flowerbed[i]=1;
                    count+= 1;
                }
            }
        }
        
        return count>=n;
    }
};