class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        
        // (Source)   <--    (target)
        // (sx,sy)    <--    (tx,ty)
        
        while(tx>=sx and ty>=sy){
            
            if(tx>ty){
                
                if(ty==sy)return (tx-sx)%sy == 0;
                tx%= ty;
            }
            else{
                
                if(tx==sx)return (ty-sy)%sx == 0;
                ty%= tx;
            }
        }
        
        return false;
    }
};