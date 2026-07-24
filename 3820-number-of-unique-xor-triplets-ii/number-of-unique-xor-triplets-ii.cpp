class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        
        // Approach 1 : Using unordered set ...
        int n = nums.size();
        
        unordered_set<int> pairXOR;
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                pairXOR.insert(nums[i] ^ nums[j]);
            }
        }

        unordered_set<int> tripletXOR;
        for(int triplet : pairXOR) {
            for(int i = 0; i < n; i++) {
                tripletXOR.insert(triplet ^ nums[i]);
            }
        }

        return tripletXOR.size();
    }
};