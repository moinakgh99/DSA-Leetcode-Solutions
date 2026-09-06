class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n = prices.size();
        int left = money;

        sort(prices.begin(), prices.end());
        
        int c = 0;
        for(int i = 0; i < n; i++) {
            left -= prices[i];
            c++;

            if(c == 2 && left >= 0) return left;
        }

        return money;
    }
};