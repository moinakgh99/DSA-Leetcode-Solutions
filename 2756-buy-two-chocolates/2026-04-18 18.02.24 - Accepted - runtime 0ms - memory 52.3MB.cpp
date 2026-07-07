class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {

        // // Brute Force
        // int n = prices.size();
        // int leftMoney = money;
        // int c = 0;
        // sort(prices.begin(), prices.end());

        // for(int i = 0; i < n; i++) {
        //     leftMoney -= prices[i];
        //     c++;

        //     if(c == 2 && leftMoney >= 0) {
        //         return leftMoney;
        //     }
        // }
        // return money;

        // Optimal Approach : Greedy 
        sort(prices.begin(), prices.end());

        int sum = prices[0] + prices[1];

        if(sum <= money) return money - sum;
        else return money;
    }
};