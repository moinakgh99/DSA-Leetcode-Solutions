#include <bits/stdc++.h>
using namespace std;

// ===================== Segment Tree Build =====================

// Segment Tree ko build karne ka function
void buildTree(int node, int left, int right, int segTree[], int values[]) {

    // Agar leaf node hai to direct value store kar do
    if (left == right) {
        segTree[node] = values[left];
        return;
    }

    int mid = left + (right - left) / 2;

    // Left aur Right subtree build karo
    buildTree(2 * node + 1, left, mid, segTree, values);
    buildTree(2 * node + 2, mid + 1, right, segTree, values);

    // Parent me dono ka maximum store hoga
    segTree[node] = max(segTree[2 * node + 1], segTree[2 * node + 2]);
}

// Segment Tree create karne ka function
int* buildSegmentTree(int values[], int size) {

    // 4*N size sufficient hoti hai Segment Tree ke liye
    int* segTree = new int[4 * size];

    buildTree(0, 0, size - 1, segTree, values);

    return segTree;
}

// ===================== Segment Tree Query =====================

// Range Maximum Query
int getMaximum(int queryLeft, int queryRight,
               int node, int left, int right,
               int segTree[]) {

    // Agar current range completely bahar hai
    if (left > queryRight || right < queryLeft)
        return INT_MIN;

    // Agar current range completely andar hai
    if (left >= queryLeft && right <= queryRight)
        return segTree[node];

    int mid = left + (right - left) / 2;

    return max(
        getMaximum(queryLeft, queryRight,
                   2 * node + 1, left, mid, segTree),

        getMaximum(queryLeft, queryRight,
                   2 * node + 2, mid + 1, right, segTree)
    );
}

// Wrapper Function
int rangeMaximumQuery(int segTree[], int size, int left, int right) {
    return getMaximum(left, right, 0, 0, size - 1, segTree);
}

class Solution {
public:

    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {

        int length = s.length();

        // Total kitne '1' already present hain
        int totalActive = count(s.begin(), s.end(), '1');

        // Har zero block ka starting aur ending index store karenge
        vector<int> zeroStart;
        vector<int> zeroEnd;

        // ===================== Zero Blocks Find =====================

        int index = 0;

        while (index < length) {

            if (s[index] == '0') {

                int start = index;

                while (index < length && s[index] == '0')
                    index++;

                zeroStart.push_back(start);
                zeroEnd.push_back(index - 1);
            }
            else {
                index++;
            }
        }

        int totalBlocks = zeroStart.size();

        // Agar sirf ek ya zero block hai
        // To trade possible nahi hai
        if (totalBlocks < 2) {
            return vector<int>(queries.size(), totalActive);
        }

        // ===================== Har Block Ki Length =====================

        vector<int> blockLength(totalBlocks);

        for (int i = 0; i < totalBlocks; i++) {
            blockLength[i] = zeroEnd[i] - zeroStart[i] + 1;
        }

        // ===================== Adjacent Pair Sum =====================

        // Example:
        // blockLength = {2,3,4,5}
        //
        // pairSum = {5,7,9}

        int pairCount = totalBlocks - 1;

        vector<int> pairSum(pairCount);

        for (int i = 0; i < pairCount; i++) {
            pairSum[i] = blockLength[i] + blockLength[i + 1];
        }

        // Pair Sum par Segment Tree bana do
        int* segTree = buildSegmentTree(pairSum.data(), pairCount);

        vector<int> answer;

        // ===================== Har Query Process =====================

        for (auto &query : queries) {

            int left = query[0];
            int right = query[1];

            // Query range ke andar first zero block
            int firstBlock =
                lower_bound(zeroEnd.begin(), zeroEnd.end(), left)
                - zeroEnd.begin();

            // Query range ke andar last zero block
            int lastBlock =
                upper_bound(zeroStart.begin(), zeroStart.end(), right)
                - zeroStart.begin() - 1;

            int bestPair = 0;

            // Kam se kam 2 zero block hone chahiye
            if (firstBlock < lastBlock) {

                // Pehla block partially aa sakta hai
                int firstLength =
                    zeroEnd[firstBlock] -
                    max(zeroStart[firstBlock], left) + 1;

                // Last block bhi partial ho sakta hai
                int lastLength =
                    min(zeroEnd[lastBlock], right) -
                    zeroStart[lastBlock] + 1;

                // Agar sirf do hi block hain
                if (lastBlock - firstBlock == 1) {

                    bestPair = firstLength + lastLength;
                }
                else {

                    // Case-1 :
                    // Pehla block partial hai aur uske next wala complete
                    int option1 =
                        firstLength + blockLength[firstBlock + 1];

                    // Case-2 :
                    // Last block partial hai aur uske previous wala complete
                    int option2 =
                        blockLength[lastBlock - 1] + lastLength;

                    // Case-3 :
                    // Beech ke complete blocks ka maximum pair
                    int middleBest =
                        rangeMaximumQuery(
                            segTree,
                            pairCount,
                            firstBlock + 1,
                            lastBlock - 2
                        );

                    bestPair = max({option1, option2, middleBest});
                }
            }

            // Existing active sections + Best gain
            answer.push_back(totalActive + bestPair);
        }

        return answer;
    }
};