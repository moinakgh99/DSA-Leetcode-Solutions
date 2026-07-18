class Solution {
public:
    const long long mod = 1e9+7;
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        long long lesser = 0, range = 0, greater = 0;

        long long swap = 0;
        for(int x : nums) {
            if( x < a) {
                swap += range + greater;
                lesser++;
            }
            else if(x >= a && x <= b) {
                swap += greater;
                range++;
            }
            else greater++;
        }

        return swap % mod;
    }
};