class Solution {
public:
    
    long long largestRectangleInTheHistogram(vector<int> &nums){
        int n= nums.size();
        
        vector<int> nsl(n,-1);
        vector<int> dp(n,0);
        
        stack<int> st;
        long long totalArea=0;
        
        for(int i=0;i<n;i++){
            
            while(!st.empty() and nums[i]<=nums[st.top()]){
                
                st.pop();
            }
            
            if(!st.empty()){
                
                nsl[i]= st.top();
                auto height= nums[i];
                auto breadth= (i-nsl[i]);
                auto area= (height*breadth);
                dp[i]+= dp[nsl[i]];
                dp[i]+= area;
            }
            
            if(nsl[i]==(-1)){
                
                auto height= nums[i];
                auto breadth= (i+1);
                auto area= (height*breadth);
                dp[i]+= area;
            }
            
            st.push(i);
        }
        
        for(int i=0;i<n;i++){
            
            totalArea+= (dp[i]);
        }
        
        return totalArea;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int n= mat.size();
        int m= mat[0].size();
        
        vector<int> nums(m,0);
        
        long long res=0;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(mat[i][j])nums[j]+=1;
                else nums[j]=0;
            }
            
            res+= largestRectangleInTheHistogram(nums);
        }
        
        return res;
    }
};