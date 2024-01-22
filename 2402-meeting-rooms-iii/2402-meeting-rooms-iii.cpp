// typedef pair<long long,int> node;
bool comp(vector<int> &a,vector<int> &b){
        
        return  a[0]<b[0];
    }
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        
        // Early startTime and Early endTime
        sort(meetings.begin(),meetings.end(),comp);
        
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
        priority_queue<int,vector<int>,greater<int>> unused;
        unordered_map<int,int> freq;
        
        for(int i=0;i<n;i++)unused.push(i);
        
        for(auto x: meetings){
            
            int start= x[0];
            int end= x[1];
            
            // Enqueue all the meetings that can be attended
            
            while(!q.empty() and q.top().first<=start){
                
                auto room= q.top().second;
                q.pop();
                unused.push(room);
            }
            
            if(!unused.empty()){
                
                auto earliestRoom= unused.top();
                unused.pop();
                freq[abs(earliestRoom)]+= 1;
                q.push({end,earliestRoom});
            }
            else{
                
                auto earliestMeeting= q.top();
                q.pop();
                auto earliestRoomAvailable= earliestMeeting.second;
                auto endTime= earliestMeeting.first;
                endTime+= (end-start);
                freq[abs(earliestRoomAvailable)]+= 1;
                q.push({endTime,earliestRoomAvailable});
            }
        }
        
        int maxi = 0;
        for(int i = 1; i < n; i++) {
            if(freq[i] > freq[maxi])
                maxi = i;
        }
        return maxi;
    }
};