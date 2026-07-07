class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int maxpr1 = 0, maxpr2 = 0;
      int bestbuy1 = prices[0], bestbuy2 = prices[0];

      for(int i = 1; i < prices.size(); i++) {
        maxpr1 = max(maxpr1, prices[i] - bestbuy1);
        maxpr2 = max(maxpr2, prices[i] - bestbuy2);

        bestbuy1 = min(bestbuy1, prices[i]);
        bestbuy2 = min(bestbuy2, prices[i] - maxpr1);
      }

      return maxpr2;
    }
};