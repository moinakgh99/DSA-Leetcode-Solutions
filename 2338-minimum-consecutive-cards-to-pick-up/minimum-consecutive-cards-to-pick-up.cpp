class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {

        // Using sliding Window .. coz finding the consecutive cards 
        int n = cards.size();
        int i = 0, j = 0;
        int len = INT_MAX;
        unordered_set<int> st;

        while(j < n) {

            if(st.count(cards[j])) {

                while(st.count(cards[j])) {
                    st.erase(cards[i]);
                    i++;
                }

                len = min(len, j - i + 2);
            }

            st.insert(cards[j]);
            j++;
        }

        return (len == INT_MAX) ? -1 : len;
    }
};