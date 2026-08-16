class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {

        // Using sliding Window .. coz finding the consecutive cards 
        // Approach 1 ..

        /*
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
        */


        // Approach 2 : Using HashMap -> just simply store krenga konsa element kis idx me present h !!
        int n = cards.size();
        int len = INT_MAX;
        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++) {
            if(mp.count(cards[i])) {
                len = min(len, i - mp[cards[i]] + 1);
            }

            mp[cards[i]] = i;
        }

        return (len == INT_MAX) ? -1 : len;
    }
};