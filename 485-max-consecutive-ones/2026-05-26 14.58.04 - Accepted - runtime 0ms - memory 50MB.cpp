class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c = 0, maxi = 0;
        for(int x : nums) {
            if(x == 1) {
                c += 1;
                maxi = max(maxi , c);
            }
            else c = 0;
        }
        return maxi;
    }
};