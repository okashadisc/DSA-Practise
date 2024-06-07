class MyCalendar {
public:
    
    //      [prevInterval]        [currInterval]       [nextInterval]
    
    //   We need to check for the overlapping conditions for both the (nextInterval) and the (prevInterval)
    
    
    map<int,int> intervals;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        if(intervals.size()==0){
            
            intervals[start]= end;
            return true;
        }
        
        // Checking for (nextInterval)
        auto nextInterval= intervals.upper_bound(start);
        
        if(nextInterval != intervals.end() and end>nextInterval->first)return false;
        
        // Checking for (prevInterval)
        if(nextInterval != intervals.begin()){
            
            nextInterval--;
            if(start<nextInterval->second)return false;
        }
        
        
        intervals[start]= end;
        
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */