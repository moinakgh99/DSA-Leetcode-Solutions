class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        /*
            Agar array me sirf 1 ya 2 elements hain,
            to jitne elements hain utne hi unique XOR values milengi.
            (Triplet me same index baar-baar choose kar sakte hain.)
        */
        if(n == 1 || n == 2) return n;

        /*
            Jab n >= 3 hota hai, tab hum 0 se lekar
            (2^k - 1) tak ke saare XOR values bana sakte hain, i.e means ki max value hmai hmesha 7 hi milegi .... agar saare bits 1 honga
            jahan 2^k, n se bada ya equal pehla power of 2 hota hai.
        */
        int res = 1;   
        while(res <= n) res *= 2;

        return res;
    }
};