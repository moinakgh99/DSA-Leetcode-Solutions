class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();

        // Using O(n) space ....
        // unordered_map<int,int> mp;
        // vector<int> res;

        // for(int &x : nums) mp[x]++;

        // for(auto &it : mp) {
        //     if(it.second == 1) res.push_back(it.first);
        // }

        // return res;


        // O(1) space ...

        /*
        
        Approach : 1) Jo number ek baaar aaye h , unko alag group me rkhenge.
            2) alag group me daalna k lia, mask k use krenga -> rightmost set bits means rightmost
            me pehla bit kis position me aaya h !!
            3) mask ko nikalna k lia -> ( XOR & -XOR )

        */

        /*

        STEPS : 1) Calculate the Total XOR ,,,
        2) calculate the mask using XOR -> XOR & -XOR
        3) mask k har ek element k saath and krenga , agar 0 aaya to grp B else 1 aaya to grp A

        */

        long long xor_r = 0;

        for(int &num : nums) {
            xor_r ^= num;
        }

        int mask = (xor_r & (-xor_r));

        int grpA = 0, grpB = 0;
        for(int &num : nums) {
            if((mask & num) != 0) grpA ^= num;
            else grpB ^= num;
        }

        return {grpA, grpB};

    }
};