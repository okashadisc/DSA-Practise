class Solution {
public:
    long long res;
    void merge(int start,int mid,int end,vector<int> &nums){
        
        int i=start,j=mid+1;
        int k=0;
        
        vector<int> sortedNums(end-start+1);
        
        
        
        // Direct Implication of Merge-Sort in an Increasing order fashioned manner
        
        //  [start   mid]   [mid+1    end]
        //        (i)               (j)
        
        
        while(i<=mid and j<=end){
            
            if(nums[i]>1L*2*nums[j]){
                
                res+= (mid-i+1);
                j++;
            }
            else{
                
                i++;
            }
        }
        i=start, j=mid+1;
        while(i<=mid and j<=end){
            
            if(nums[i]<=nums[j])sortedNums[k++]= nums[i++];
            else sortedNums[k++]= nums[j++];
        }
        
        while(i<=mid){
            
            sortedNums[k++]= nums[i++];
        }
        
        while(j<=end){
            
            sortedNums[k++]= nums[j++];
        }
        
        k=0;
        i=start;
        while(i<=end){
            
            nums[i++]= sortedNums[k++];
        }
    }
    void mergeSort(int start,int end,vector<int> &nums){
        
        //base case
        if(start>=end)return;
        
        //recursive case
        
        int mid= start + (end-start)/2;
        
        mergeSort(start,mid,nums);
        mergeSort(mid+1,end,nums);
        
        merge(start,mid,end,nums);
    }
    int reversePairs(vector<int>& nums) {
        int n= nums.size();
        
        int start=0, end=n-1;
        res=0;
        
        mergeSort(start,end,nums);
        
        return res;
    }
};