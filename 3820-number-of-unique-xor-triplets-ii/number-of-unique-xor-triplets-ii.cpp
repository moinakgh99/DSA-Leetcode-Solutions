class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        
        // Approach 1 : Using unordered set ...
        // int n = nums.size();
        
        /*
            Pehle saare possible pair XOR nikal lenge.
            Maine j = i se start kiya hai kyunki question me
            same index ko bhi multiple baar choose kar sakte hain.
            
            unordered_set use kiya hai taaki duplicate XOR values
            automatically remove ho jaaye.
        */
        // unordered_set<int> pairXOR;
        // for(int i = 0; i < n; i++) {
        //     for(int j = i; j < n; j++) {
        //         pairXOR.insert(nums[i] ^ nums[j]);
        //     }
        // }

        /*
            Ab har pair XOR ke saath array ke har element ka
            XOR karenge.

            (a ^ b) ^ c = a ^ b ^ c

            Is tarah saare possible triplet XOR values mil jaayengi.

            Fir se unordered_set use kiya hai taaki sirf unique
            XOR values hi store ho.
        */
        // unordered_set<int> tripletXOR;
        // for(int triplet : pairXOR) {
        //     for(int i = 0; i < n; i++) {
        //         tripletXOR.insert(triplet ^ nums[i]);
        //     }
        // }

        // return tripletXOR.size();



        // Approach 2 : Using vector instead of set ...
        int n = nums.size();

        int mx = *max_element(nums.begin(), nums.end());

        int m = 1;
        while(m <= mx) {
            m *= 2;
        }

        vector<bool> pairXOR(m, false);
        vector<bool> tripletXOR(m, false);

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                pairXOR[nums[i] ^ nums[j]] = true;
            }
        }

        for(int i = 0; i < m; i++) {
            if(pairXOR[i] == true) {
                for(int &num : nums) {
                    tripletXOR[i ^ num] = true;
                }
            }
        }

        int c = 0;
        for(int i = 0; i < m; i++) {
            if(tripletXOR[i] == true) c++;
        }

        return c;
    }
};