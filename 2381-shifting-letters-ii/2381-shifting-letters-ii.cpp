class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n= s.length();
        
        vector<int> dir(n+1,0);
        
        for(int i=0;i<shifts.size();i++){
            
            auto left= shifts[i][0];
            auto right= shifts[i][1];
            auto val= (shifts[i][2]==0?-1:1);
            
            dir[left]+= (val);
            dir[right+1]-= val;
        }
        
        // Accumulating the Effect
        
        for(int i=1;i<n;i++){
            
            dir[i]= (dir[i] + dir[i-1]);
        }
        
        
        // Making the shifts based on the accumulated Effect
        
        string res= "";
        
        for(int i=0;i<n;i++){
            
            auto indx= ((s[i]-97) + dir[i])%26;
            
            if(indx<0)indx+= 26;
            
            char ch= (indx + 97);
            res.push_back(ch);
        }
        
        
        return res;
    }
};