class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n= nums.size();
        
        if(n==1)return 0;
        
        vector<int> minimumOfBucket(n,INT_MAX);
        vector<int> maximumOfBucket(n,INT_MIN);
        
        //  [Bucket 1]   [Bucket 2]   [Bucket 3]  [Bucket 4]
        //     [0 7]        [8 15]       [16 23]    [24 31]
        //                    [Range of Numbers]
        
        
       int maximum= *max_element(nums.begin(),nums.end());
        int minimum= *min_element(nums.begin(),nums.end());
        
        int bucketSize= (int) ceil((double)(maximum-minimum)/(n-1));
        
        if(bucketSize == 0)return 0;
        
        for(int i=0;i<n;i++){
            
            int number= nums[i];
            int bucketIndx= (number-minimum)/bucketSize;
            
            minimumOfBucket[bucketIndx]=min(minimumOfBucket[bucketIndx],number);
            maximumOfBucket[bucketIndx]= max(maximumOfBucket[bucketIndx],number);
        }
        
        
        //   [min  max]   [min   max]   [min   max]
        
        int previousMax= maximumOfBucket[0];
        int maxDiff= bucketSize;
        
        if(minimum == maximum)return 0;
        
        for(int i=1;i<n;i++){
            
            if(minimumOfBucket[i] == INT_MAX)continue;
            
            maxDiff=max(maxDiff, minimumOfBucket[i]-previousMax);
            previousMax= maximumOfBucket[i];
        }
        
        
        return maxDiff;
        
    }
};