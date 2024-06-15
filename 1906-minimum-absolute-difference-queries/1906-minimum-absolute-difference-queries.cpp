class Solution {
public:
    vector<int> res;
    struct query{
        
        int l;
        int r;
        int indx;
    };
    
    void moveLR(int &L,int &R,query Q,vector<int> &st,vector<int> &nums){
        
        while(L< Q.l){
            
            st[nums[L]]-=1;
            L++;
        }
        
        while(R > Q.r){
            
            st[nums[R]]-=1;
            R--;
        }
        
        while(L> Q.l){
            
            L--;
            st[nums[L]]+=1;
        }
        
        while(R< Q.r){
            
            R++;
            st[nums[R]]+=1;
        }
        
    }
    
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n= nums.size();
        
        vector<query> que;
        for(int i=0;i<queries.size();i++){
        
            // {l,r,i};
            que.push_back({queries[i][0],queries[i][1],i});
        }
        
        // Sorting the Queries to Optimize depending upon the BLOCK SIZE
        
        int block= sqrt(n);
        
        sort(que.begin(),que.end(),[&](auto &a,auto &b){
            
            if(a.l/block != b.l/block)return a.l/block<b.l/block;
            
            return a.r<b.r;
        });
        
        
        vector<int> st(101,0);
        
        //       {L and R}   -->    {GLOBAL}
        
        
        int L= que[0].l;
        int R= que[0].l;
        st[nums[L]]+=1;
        
        res.resize(queries.size(),-1);
        
        for(int i=0;i<que.size();i++){
            
            moveLR(L,R,que[i],st,nums);
            
            int indx= que[i].indx;
            int prev= (-1);
            int minVal= INT_MAX;
            
            for(int j=1;j<=100;j++){
                
                
                if(st[j]){
                    
                    if(prev != (-1)){
                        
                        minVal= min(minVal,abs(j-prev));
                    }
                    prev= j;
                }
            }
            
            if(minVal != INT_MAX)res[indx]= minVal;
        }
        
        
        return res;
    }
};