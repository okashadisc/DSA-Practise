#define A(i) nums[(2*i + 1) % (n|1)]
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n= nums.size();
        
        int mid=0,low=0;
        int high= (n-1);
        
        auto midPoint= nums.begin() + n/2;
        
        nth_element(nums.begin(),midPoint,nums.end());
        
        auto median= *midPoint;
        
        //  [3-way-partitioning] and implicit
        
        //       (Re-wiring) of (Indexes)
        
        
        while(mid<=high){
            
            if(A(mid)>median){
                
                swap(A(mid),A(low));
                mid++;
                low++;
            }
            else if(A(mid) == median)mid++;
            else{
                
                swap(A(mid),A(high));
                high--;
            }
        }
        
        
        return;
    }
};