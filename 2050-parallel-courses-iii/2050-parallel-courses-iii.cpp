typedef pair<int,int> node;
class Solution {
public:
    unordered_map<int,vector<int>> h;
    vector<int> inDegree;
    
    void makeGraph(vector<vector<int>> &relations,int n){
        
        for(int i=0;i<relations.size();i++){
            
            h[relations[i][0]].push_back(relations[i][1]);
            inDegree[relations[i][1]]+=1;
        }
    }
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        
        inDegree.resize(n+1,0);
        makeGraph(relations,n);
        
        cout<<endl;
        queue<node> q;
        
        for(int i=1;i<=n;i++){
            
            if(!inDegree[i])q.push({i,0});
        }
        
        vector<int> completionTime(n+1,0);
        
        
        while(!q.empty()){
            
            auto ele= q.front();
            q.pop();
            
            auto maxTimeTakenToCompleteAllCoursesTillPrevNode= ele.second;
            auto node= ele.first;
            
            auto maxTimeTakenToCompleteAllCoursesTillCurrNode= maxTimeTakenToCompleteAllCoursesTillPrevNode + time[node-1];
            completionTime[node]= maxTimeTakenToCompleteAllCoursesTillCurrNode;
            
            for(auto nextNode:h[node]){
                
                inDegree[nextNode]-=1;
                
                completionTime[nextNode]=max(completionTime[nextNode],maxTimeTakenToCompleteAllCoursesTillCurrNode);
                
                if(!inDegree[nextNode])q.push({nextNode,completionTime[nextNode]});
            }
        }
        
        
        return *max_element(completionTime.begin(),completionTime.end());
        
    }
};