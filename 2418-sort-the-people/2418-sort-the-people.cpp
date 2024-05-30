typedef pair<int,string> node;
class Solution {
public:
    static bool comp(node &a,node &b){
        
        return a.first>b.first;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n= names.size();
        
        vector<node> nums;
        for(int i=0;i<n;i++){
            
            nums.push_back({heights[i],names[i]});
        }
        
        sort(nums.begin(),nums.end(),comp);
        
        vector<string> res;
        for(int i=0;i<n;i++)res.push_back(nums[i].second);
        
        return res;
    }
};