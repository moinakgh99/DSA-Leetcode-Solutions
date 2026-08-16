class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int lSum = 0, rSum = 0, maxSum = 0;

        // Pehle left se saare uthalo points ...
        for(int i = 0; i < k; i++) {
            lSum += cardPoints[i];
        }

        maxSum = lSum;
        
        // ab dheere dheere left se km krte jaao aur right wale jhorde jaao ...
        int rIdx = n-1;
        for(int i = k-1; i >= 0; i--) {
            lSum -= cardPoints[i];
            rSum += cardPoints[rIdx];
            rIdx--;

            maxSum = max(maxSum, lSum + rSum);
        }

        return maxSum;
    }
};