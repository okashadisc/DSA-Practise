class Solution {
public:
    void utility(int indx,string s,string out,vector<string>&ans)
    {
        //base case
        if(indx==s.length())
        {
            ans.push_back(out);
            return;
        }
        //recursive case
        if(!isdigit(s[indx]))
        {
            //2 choices--->uppercase or lowercase
            string c1=out;
            c1.push_back(tolower(s[indx]));
            utility(indx+1,s,c1,ans);
            
            string c2=out;
            c2.push_back(toupper(s[indx]));
            utility(indx+1,s,c2,ans);
    
            
        }
        else
        {
            string c=out;
            c.push_back(s[indx]);
            utility(indx+1,s,c,ans);
        }
    }
    vector<string> letterCasePermutation(string s) {
        int indx=0;
        vector<string>ans;
        string out="";
        utility(indx,s,out,ans);
        return ans;
        
    }
};