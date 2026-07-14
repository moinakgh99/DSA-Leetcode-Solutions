class Solution {
public:
    int t[201][201][201];
    int mod = 1e9+7;

    int solve(vector<int>& nums, int idx, int gcdSeq1, int gcdSeq2) {

        if(idx == nums.size()) {
            // check krna k lia ki koi sequnce bna h !!
            bool nonEmpty = (gcdSeq1 != 0) && (gcdSeq2 != 0);
            bool gcdMatch = (gcdSeq1 == gcdSeq2);
            return nonEmpty && gcdMatch ? 1 : 0;
        }

        if(t[idx][gcdSeq1][gcdSeq2] != -1) return t[idx][gcdSeq1][gcdSeq2];

        int skip = solve(nums, idx + 1, gcdSeq1, gcdSeq2);
        int seq1 = solve(nums, idx + 1, __gcd(gcdSeq1, nums[idx]), gcdSeq2);
        int seq2 = solve(nums, idx + 1, gcdSeq1, __gcd(gcdSeq2, nums[idx]));

        return t[idx][gcdSeq1][gcdSeq2] = (0LL + skip + seq1 + seq2) % mod;
    }

    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));

        return solve(nums, 0, 0, 0);  // array, idx, gcd of first seq1, gcd of sec seq2
    }
};