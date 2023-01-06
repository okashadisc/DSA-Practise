class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        float h=   double(hour%12 + (float)minutes/60)*30;
        
        float m= minutes*6;
        
        float angle= abs(h-m);
        
        return min(angle,360-angle);
    }
};