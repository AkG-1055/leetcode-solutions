class Solution {
public:
    double angleClock(int hour, int minutes) {
        float hourAngle = (hour % 12) * 30 + 0.5 * minutes;
        float minAngle = minutes * 6;
        
        float diff = abs(hourAngle - minAngle);
        
        return min(diff, 360 - diff);
    }
};