class Solution {
public:
    long long upperLimit= (pow(2,31)-1);
    long long lowerLimit= (-pow(2,31))/10;
    int nextGreaterElement(int n) {
        
        auto nums= to_string(n);
        int len= nums.length();
        
        // Next Permutation Logic
        
        
        bool sorted= true;
        
        int indx1= (-1);
        int indx2= (-1);
        
        for(int i=len-2;i>=0;i--){
            
            if((nums[i]-48)<(nums[i+1]-48)){
                
                sorted= false;
                indx1= i;
                break;
            }
        }
        
        
        if(sorted){
            
            return (-1);
        }
        else{
            
            for(int i=len-1;i>=0;i--){
                
                if((nums[i]-48)>(nums[indx1]-48)){
                    
                    indx2= i;
                    break;
                }
            }
            
            swap(nums[indx1],nums[indx2]);
            reverse(nums.begin()+indx1+1,nums.end());
        }
        
        auto num= stoll(nums);
        
        if(num>=1 and num<=upperLimit)return stoi(nums);
        
        return (-1);
    }
};