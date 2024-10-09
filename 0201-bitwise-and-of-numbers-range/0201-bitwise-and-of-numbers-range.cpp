class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        // Keep Dropping the (lowest) (set) bits
        while(left<right){
            
            right= (right) & (right-1);
        }
        
        
        return right;
    }
};