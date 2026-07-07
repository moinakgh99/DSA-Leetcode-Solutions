class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftSum = 0, maxSum = 0;
        for(int  i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }
        maxSum = leftSum;

        int r = n-1;
        for(int i = k-1; i >= 0; i--) {
            leftSum -= cardPoints[i];
            leftSum += cardPoints[r];
            r--;
            maxSum = max(leftSum, maxSum);
        }
        return maxSum;
    }
};