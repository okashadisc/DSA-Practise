class Solution {
public:
    bool canPartition(string &str,int num,int original){
        int n= str.length();
        
        //base case
        if(str == ""){
            
            if(num==original)return true;
            
            return false;
        }
        
        //recursive case
        
        for(int i=0;i<n;i++){
            
            auto left= str.substr(0,i+1);
            auto leftNum= stoi(left);
            
            auto right= str.substr(i+1);
            
            if(canPartition(right,leftNum + num,original))return true;
        }
        
        return false;
    }
    int punishmentNumber(int n) {
        
        long long sum=1;
        for(int i=2;i<=n;i++){
            
            auto str= to_string(i*i);
            
            if(canPartition(str,0,i))cout<<i<<endl, sum+= (i*i);
        }
        
        
        return (sum);
    }
};