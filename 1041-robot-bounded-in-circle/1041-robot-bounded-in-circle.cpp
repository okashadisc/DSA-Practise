class Solution {
public:
    bool originCheck(long long x,long long y){
        
        return x==0 and y==0;
    }
    bool isRobotBounded(string instructions) {
        int n= instructions.length();
        
        char dir= 'N';
        long long x=0,y=0;
        
            for(int i=0;i<n;i++){
                
                auto incoming= instructions[i];
                
                if(incoming=='G'){
                    
                    y+= (dir=='N'?1:0);
                    y+= (dir=='S'?-1:0);
                    x+= (dir=='E'?1:0);
                    x+= (dir=='W'?-1:0);
                }
                else{
                    
                    if(dir=='N'){
                        
                        dir= (incoming=='L'?'W':'E');
                    }
                    else if(dir=='S'){
                        
                        dir= (incoming=='L'?'E':'W');
                    }
                    else if(dir=='W'){
                        
                        dir= (incoming=='L'?'S':'N');
                    }
                    else if(dir=='E'){
                        
                        dir= (incoming=='L'?'N':'S');
                    }
                }
            }
            
            if(originCheck(x,y) or dir != 'N')return true;
                              
            return false;                
    }
};