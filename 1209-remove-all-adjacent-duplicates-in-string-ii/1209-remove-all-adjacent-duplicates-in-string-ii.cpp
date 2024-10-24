typedef pair<char,int> node;
class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n= s.length();
        
        stack<node> st;
        
        for(int i=0;i<n;i++){
            
            auto ch= s[i];
            if(!st.empty() and ch == st.top().first){
                
                auto count= st.top().second;
                if(!st.empty() and count+1 == k)st.pop();
                else{
                    
                    st.pop();
                    st.push({ch,count+1});
                }
            }
            else{
                
                st.push({ch,1});
            }
        }
        
        string res="";
        while(!st.empty()){
            
            auto node= st.top();
            st.pop();
            
            auto count= node.second;
            for(int i=0;i<count;i++)res+= node.first;
        }
        
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};