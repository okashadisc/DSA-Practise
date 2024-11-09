class Solution {
public:
    unordered_map<int,vector<int>> graph;
    unordered_map<string,int> freq;
    vector<pair<int,string>> res;
    unordered_map<int,bool> visited;
    
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& graph, int id, int level) {
        
        
        long long steps=0;
        
        queue<int> q;
        
        q.push(id);
        visited[id]= true;
        
        while(!q.empty()){
            
            int n= q.size();
            
            if(steps==level){
                
                while(!q.empty()){
                    
                    int ele= q.front();
                    q.pop();
                    
                    for(int i=0;i<watchedVideos[ele].size();i++){
                        
                        freq[watchedVideos[ele][i]]+=1;
                    }
                }
                
                break;
            }
            while(n--){
                
                auto node= q.front();
                q.pop();
                
                for(auto nbr:graph[node]){
                    
                    if(!visited[nbr]){
                        visited[nbr]= true;
                        q.push(nbr);
                    }
                }
            }
            
            steps+=1;
        }
        
        
        for(auto i:freq)res.push_back({i.second,i.first});
        sort(res.begin(),res.end());
        
        vector<string> ans;
        for(int i=0;i<res.size();i++)ans.push_back(res[i].second);
        
        
        return ans;
        
    }
};