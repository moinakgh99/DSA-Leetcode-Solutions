class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> mp;

        // first we handle the cases of 1
        long long one = 0;
        for(auto &x : nums) {
            if(x == 1) one++;
            else mp[x]++;
        }

        // if 1 is even ,  we will just minus 1 to make it odd.
        // coz odd divides the content in equal halves
        if(one > 0 && one % 2 == 0) one--;
        int res = one;

        for(auto &it : mp) {
            long long val = it.first;
            long long base = sqrt(val);

            // to reduce unnecessary checks
            // first we will start with smaller numbers, if it is present then continue;
            // for 2 , sequence will be 2->4->16->32 etc
            // now if we take 4, then sequence will be 4->16->32 etc, which is repeated in 2 as well
            // so for every curr val we will take sqrt, and multiply with itself to check if it is equal to curr val and also check the count should be greater than 1 and freq should be greater than or equal to 2


            if((base * base == val) && mp.count(base) && mp[base] >= 2) continue;
            
            int c = 0;
            while(mp.count(val) && mp[val] >= 2) {
                c += 2;
                val = (long long) val * val;
            }

            // if the element is not present or the freq is less than 2

            if(mp.count(valm && p[val] == 1) c++; // if freq is 1 , we just simply increment it to make it key
            else c--; // otherwise if the elemnt is not present, we just simply take the previous element and reduce the value of c to make it key..

            res = max(res, c);
        }
        return res;
    }
};