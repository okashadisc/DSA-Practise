class Solution {
public:
    vector<string>parse(string input){
        vector<string>subRes;
        
//         int left=0;
//         for(int i=0;i<input.length();i++){
//             if(input[i]==','){
//                 string temp=input.substr(left,i-left);
//                 left=i+1;
//                 subRes.push_back(temp);
//             }
//         }
        
        stringstream ss(input);
        string temp;
        
        while(getline(ss,temp,',')){
            subRes.push_back(temp);
        }
        
        return subRes;
    }
    vector<string> braceExpansionII(string expression) {
        queue<string>q;
        
        set<string>res;
        
        q.push(expression);
        
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            auto left=curr.find('{');
            if(left==(-1)){
                res.insert(curr);
                continue;
            }
            
            auto indx=left;
            while(indx<curr.length() and curr[indx] != '}'){
                if(curr[indx]=='{')left=indx;
                indx++;
            }
            auto right=indx;
            
            auto processed=curr.substr(0,left);
            auto processingString=curr.substr(left+1,(right-left-1));
            auto unprocessed=curr.substr(right+1);
            
            vector<string> processing= parse(processingString);
            
            for(auto x:processing){
                q.push(processed+x+unprocessed);
            }
        }
        
        vector<string>finalRes(res.begin(),res.end());
        
        // while(!res.empty()){
        //     finalRes.push_back(*res.begin());
        //     auto address=res.find(*res.begin());
        //     if(address != res.end())res.erase(address);
        // }
    
        
        return finalRes;
    }
};