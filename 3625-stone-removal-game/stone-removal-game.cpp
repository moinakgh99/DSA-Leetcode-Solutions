class Solution {
public:
    bool canAliceWin(int n) {
        if(n < 10) return false;

        int take = 10, steps = 0;
        while(n >= take) {
            n -= take;
            take -= 1;
            steps++;
        }

        return steps % 2 == 1;
    }
};