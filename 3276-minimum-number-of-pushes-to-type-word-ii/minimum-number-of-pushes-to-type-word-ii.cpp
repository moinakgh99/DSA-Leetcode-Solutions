class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(auto &ch : word) freq[ch - 'a']++;

        sort(freq.begin(), freq.end(), greater<>{});

        /*
        Frequency ko descending order me sort kiya,
        taaki sabse jyada aane wale characters ko
        sabse kam key presses mile.
        */
        int push = 0;
        for(int i = 0; i < 26; i++) {
            int times = freq[i];

            if(times == 0) break;

            int press = (i / 8) + 1;

            push += times * press;
        }

        return push;
    }
};