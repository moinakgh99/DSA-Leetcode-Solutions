class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        // Brute Force Approach -> Memory Limit exceed
        // int n = nums.size();
        // vector<int> gcdPairs;

        // for(int i = 0; i < n; i++) {
        //     for(int j = i + 1; j < n; j++) {
        //         gcdPairs.push_back(__gcd(nums[i], nums[j]));
        //     }
        // }

        // sort(gcdPairs.begin(), gcdPairs.end());

        // vector<int> res;
        // for(int i = 0; i < queries.size(); i++) {
        //     res.push_back(gcdPairs[queries[i]]);
        // }

        // return res;



        // Optimal Approach ...
        int n = nums.size();
        int maxNumber = *max_element(nums.begin(), nums.end());

        // divisorCount[d] = Number of elements divisible by d
        vector<int> divisorCount(maxNumber + 1, 0);

        for (int num : nums) {
            for (int divisor = 1; divisor * divisor <= num; divisor++) {
                if (num % divisor == 0) {
                    divisorCount[divisor]++;

                    int otherDivisor = num / divisor;
                    if (otherDivisor != divisor) {
                        divisorCount[otherDivisor]++;
                    }
                }
            }
        }

        // exactGcdPairs[g] = Number of pairs having GCD exactly equal to g
        vector<long long> exactGcdPairs(maxNumber + 1, 0);

        for (int gcd = maxNumber; gcd >= 1; gcd--) {

            long long divisibleElements = divisorCount[gcd];

            // Total pairs divisible by gcd
            exactGcdPairs[gcd] =
                divisibleElements * (divisibleElements - 1) / 2;

            // Remove pairs already counted for multiples of gcd
            for (int multiple = 2 * gcd; multiple <= maxNumber; multiple += gcd) {
                exactGcdPairs[gcd] -= exactGcdPairs[multiple];
            }
        }

        // prefixPairs[g] = Total pairs having GCD <= g
        vector<long long> prefixPairs(maxNumber + 1, 0);

        for (int gcd = 1; gcd <= maxNumber; gcd++) {
            prefixPairs[gcd] = prefixPairs[gcd - 1] + exactGcdPairs[gcd];
        }

        vector<int> answer;

        for (long long queryIndex : queries) {

            int left = 1;
            int right = maxNumber;
            int gcdAnswer = 1;

            while (left <= right) {

                int midGcd = left + (right - left) / 2;

                if (prefixPairs[midGcd] > queryIndex) {
                    gcdAnswer = midGcd;
                    right = midGcd - 1;
                } else {
                    left = midGcd + 1;
                }
            }

            answer.push_back(gcdAnswer);
        }

        return answer;
    }
};