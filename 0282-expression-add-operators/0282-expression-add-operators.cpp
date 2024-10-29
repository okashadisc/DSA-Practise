class Solution {
public:
    vector<string> res;
    unordered_set<string> visited;
    
    void dfs(int indx,long long pastRes,char pastSign,string currRes,string &str,int target,int n,long long prevNum){
        
        if(currRes=="00" or currRes=="000")return;
        //base case
        if(indx>=n){
            
            // currRes.pop_back();
            
            if(pastRes == target and !visited.count(currRes)){
                res.push_back(currRes);
                visited.insert(currRes);
            }
            return;
        }
        
        //recursive case
        
        long long number=0;
        for(int j=indx;j<n;j++){
            
            if(j>indx and str[indx]=='0')break;
            number= number*10 + (str[j]-48);
            // if(pastSign=='+')pastRes+= number;
            // else if(pastSign=='-')pastRes-=number;
            // else if(pastSign=='*')pastRes= pastRes - prevNum + prevNum*number;   // [   4-8*7   ]
            
            if(indx==0){
                
                dfs(j+1,pastRes+number,pastSign,to_string(number),str,target,n,number);
            }
            
            else{
            dfs(j+1,pastRes+number,'+',currRes+"+"+to_string(number),str,target,n,number);
            dfs(j+1,pastRes-number,'-',currRes+"-"+to_string(number),str,target,n,-number);
        dfs(j+1,pastRes - prevNum + prevNum*1L*number,'*',currRes+"*"+to_string(number),str,target,n,prevNum*1L*number);
            }
        
        }
    }
    vector<string> addOperators(string str, int target) {
        int n= str.length();
        
        string number= "";
        
        dfs(0,0,'#',number,str,target,n,0);
        
        return res;
    }
};