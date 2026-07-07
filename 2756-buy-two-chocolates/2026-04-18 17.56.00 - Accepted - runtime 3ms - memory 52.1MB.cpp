class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n = prices.size();
        int leftMoney = money;
        int c = 0;
        sort(prices.begin(), prices.end());

        for(int i = 0; i < n; i++) {
            leftMoney -= prices[i];
            c++;

            if(c == 2 && leftMoney >= 0) {
                return leftMoney;
            }
        }
        return money;
    }
};