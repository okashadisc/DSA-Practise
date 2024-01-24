class Solution {
public:
   unordered_map<int,vector<int>>h= {
       {0,{1,3}},
       {1,{0,2,4}},
       {2,{1,5}},
       {3,{0,4}},
       {4,{1,3,5}},
       {5,{2,4}}
   };
    
    string utility(int indx,int nbr,string node){
        
        string temp= node;
        swap(temp[indx],temp[nbr]);
        
        return temp;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        int n= board.size();
        int m= board[0].size();
        
        unordered_set<string> visited;
        queue<string> q;
        string finalState= "123450";
        
        string startNode= "";
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                startNode+= to_string(board[i][j]);
            }
        }
        
        q.push(startNode);
        
        long long steps=0;
        while(!q.empty()){
            
            int size= q.size();
            while(size--){
                
                string node= q.front();
                q.pop();
                
                if(node==finalState)return steps;
                
                int indx= node.find('0');
                for(auto nbr:h[indx]){
                    
                    string nextNode= utility(indx,nbr,node);
                    if(!visited.count(nextNode)){
                        
                        visited.insert(nextNode);
                        q.push(nextNode);
                    }
                }
            }
            
            steps+=1;
        }
        
        return (-1);
    }
};