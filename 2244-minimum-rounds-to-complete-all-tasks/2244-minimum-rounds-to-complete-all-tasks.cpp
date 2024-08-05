typedef pair<int,int> node;
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n= tasks.size();
        
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++)freq[tasks[i]]+=1;
        
        multiset<node> st;
        for(auto i:freq)st.insert({i.second,i.first});
        
        long long count=0;
        
        while(!st.empty()){
            
            auto val= *st.begin();
            st.erase(st.find(val));
            
            auto freqVal= val.first;
            auto task= val.second;
            
            // cout<<task<<"-->"<<freqVal<<endl;
            if(freqVal==2 or freqVal==3 or freqVal>3){
                
                if(freqVal==2)freq[task]-=2;
                else if(freqVal==3)freq[task]-=3;
                else if(freqVal % 3 == 0){
                    
                    freq[task]-=3;
                }
            else if(freqVal % 2 == 0){
                
                freq[task]-=2;
            }
            else{
                
                freq[task]-=3;
            }
                if(freq[task] == 1)return (-1);
                count+=1;
                if(freq[task])st.insert({freq[task],task});
                if(!freq[task])freq.erase(task);
            }
        }
        
//         for(auto i:freq){
            
//             cout<<i.first<<" "<<i.second<<endl;
//         }
        for(auto i:freq)if(i.second)return (-1);
        
        
        return count;
    }
};