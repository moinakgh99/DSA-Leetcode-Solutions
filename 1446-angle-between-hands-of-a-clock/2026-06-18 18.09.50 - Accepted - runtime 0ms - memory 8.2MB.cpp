class Solution {
public:
    double angleClock(int hour, int minutes) {
       double hours = (hour % 12) * 30 + minutes * 0.5;
       double minute = 6 * minutes;
       double theta = abs(hours - minute);
       return min(theta, 360 - theta);
    }
};