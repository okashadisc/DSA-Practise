class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n= cards.size();
        
        unordered_map<int,int> window;
       unordered_set<int> st;
        int minLen= INT_MAX;
        long long valid=0;
        
        int left=0,right=0;
        
        while(right<n){
            
            window[cards[right]]+=1;
            
            if(window[cards[right]]==2){
                
                st.insert(cards[right]);
                valid+=1;
            }
            
            
           // cout<<left<<"-->"<<right<<endl;
            while(valid==1 and st.size()){
                
                minLen=min(minLen,right-left+1);
                window[cards[left]]-=1;
                
                if(st.count(cards[left]) and window[cards[left]]<2){
                    st.erase(st.find(cards[left]));
                    valid-=1;
                }
                
                if(!window[cards[left]]){
                    
                   if(st.count(cards[left])){
                       valid-=1;
                       // st.erase(st.find(cards[left]));
                   }
                    window.erase(cards[left]);
                }
                
                left++;
            }
            // for(int i=left;i<=right;i++)cout<<cards[i]<<" ";
            // cout<<endl;
            
            right++;
        }
        
        
        return (minLen==INT_MAX)?(-1):minLen;
    }
};