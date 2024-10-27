typedef pair<int,int> node;
class Solution {
public:
    
    map<node,int> dp;
    int dfs(int indx,int prev,vector<int> &nums1,vector<int> &nums2,int n){
        
        //base case
        if(indx>=n)return 0;
        
        //recursive case
        if(dp.find({indx,prev}) != dp.end())return dp[{indx,prev}];
        
        int take= 1e9+7;
        int dontTake= 1e9+7;
        
         // Once we Simply Exclude any operation
        if(nums1[indx]>prev)dontTake= 0 + dfs(indx+1,nums1[indx],nums1,nums2,n);
        
        // Once we Include an operation
        
        auto itr= upper_bound(nums2.begin(),nums2.end(),prev);
        
        
        if(itr != nums2.end()){
            
            auto nextIndx= itr - nums2.begin();
            
            auto nextElementGreaterThanPrev= nums2[nextIndx];
            
           take= 1 + dfs(indx+1,nextElementGreaterThanPrev,nums1,nums2,n);
        }
        
        
        return dp[{indx,prev}]= min({take,dontTake});
    }
    int makeArrayIncreasing(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        
        sort(nums2.begin(),nums2.end());
        
        // dp.resize(2005,vector<int>(1e9+7,-1));
        auto res= dfs(0,INT_MIN,nums1,nums2,n);
        
        if(res == 1e9 + 7)return (-1);
        
        return res;
    }
};