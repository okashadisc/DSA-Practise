class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n= pushed.size();
        
        stack<int> input;
        stack<int> output;
        
        for(int i=n-1;i>=0;i--)output.push(popped[i]);
        
        for(int i=0;i<n or !output.empty();i++){
            
            input.push(pushed[i]);
            
            while(!input.empty() and !output.empty() and  input.top() == output.top()){
                
                cout<<input.top()<<" "<<output.top()<<endl;
                input.pop();
                output.pop();
                
            }
            
            if(i == n-1 and !input.empty() and !output.empty() and input.top() != output.top()){
                return false;
            }
            
        }
        
        
        
        
        if(input.empty() and !output.empty())return false;
        
        if(output.empty() and !input.empty())return false;
        
        return true;
    }
};