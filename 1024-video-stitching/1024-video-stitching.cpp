class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b){
        
        return a[0]<b[0];
    }
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n= clips.size();
        
        sort(clips.begin(),clips.end(),comp);
        
        int prevEnd=0;
        long long count=0;
        
        for(int i=0;i<n;){
            
            if(clips[i][0]>prevEnd)return (-1);
            
            int maxEnd= prevEnd;
            while(i<n and clips[i][0]<=prevEnd){
                
                // We will keep going, while we can
                // We will keep merging the intervals
                
                maxEnd=max(maxEnd,clips[i][1]);
                i++;
            }
            
            count+=1;
            prevEnd= maxEnd;
            
            if(prevEnd>=time)return count;
        }
        
        
        return (-1);
    }
};