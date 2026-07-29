class Solution {
public:

    // nCr calculate karne ka function
    // Agar result k se bada ho jaye, toh wahi return kar dete hain
    // kyunki hume exact value ki zarurat nahi hai.
    long long calculateCombination(int total, int choose, int limit) {

        // nCr == nC(n-r)
        choose = min(choose, total - choose);

        long long result = 1;

        for (int i = 1; i <= choose; i++) {
            result = result * (total - choose + i) / i;

            // Overflow aur unnecessary calculation se bachne ke liye
            if (result >= limit)
                return limit;
        }

        return result;
    }

    string smallestPalindrome(string s, int k) {

        int n = s.length();

        // Agar string odd length ki hai toh middle character fix rahega.
        char middleCharacter = ' ';
        if (n % 2 == 1) {
            middleCharacter = s[n / 2];
        }

        // Har character ki frequency store karenge.
        vector<int> frequency(26, 0);

        for (int i = 0; i < n; i++) {

            // Odd length me middle character ko ignore karenge.
            if (n % 2 == 1 && i == n / 2)
                continue;

            frequency[s[i] - 'a']++;
        }

        // Sirf half frequency ki zarurat padegi.
        for (int i = 0; i < 26; i++) {
            frequency[i] /= 2;
        }

        string firstHalf = "";

        int halfLength = n / 2;

        // Ek-ek karke palindrome ke first half ko build karenge.
        for (int position = 0; position < halfLength; position++) {

            bool characterPlaced = false;

            // Har alphabet ko try karte hain.
            for (int ch = 0; ch < 26; ch++) {

                if (frequency[ch] > 0) {

                    // Temporarily is character ko choose karte hain.
                    frequency[ch]--;

                    long long totalWays = 1;
                    int remainingLetters = 0;

                    // Kitne letters abhi bach gaye.
                    for (int i = 0; i < 26; i++) {
                        remainingLetters += frequency[i];
                    }

                    // Remaining letters se kitne unique permutations ban sakte hain.
                    for (int i = 0; i < 26; i++) {

                        if (frequency[i] > 0) {

                            totalWays *= calculateCombination(
                                remainingLetters,
                                frequency[i],
                                k
                            );

                            remainingLetters -= frequency[i];
                        }

                        if (totalWays >= k)
                            break;
                    }

                    // Agar kth palindrome isi branch me hai,
                    // toh isi character ko fix kar do.
                    if (totalWays >= k) {

                        firstHalf.push_back(ch + 'a');
                        characterPlaced = true;
                        break;
                    }

                    // Warna itne saare palindromes skip kar do.
                    k -= totalWays;

                    // Frequency wapas restore kar do.
                    frequency[ch]++;
                }
            }

            // Agar koi bhi character place nahi ho paya,
            // toh kth palindrome exist hi nahi karta.
            if (!characterPlaced)
                return "";
        }

        // Second half banane ke liye first half ko reverse kar do.
        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());

        // Agar odd length hai toh middle character add kar do.
        if (middleCharacter != ' ') {
            firstHalf.push_back(middleCharacter);
        }

        return firstHalf + secondHalf;
    }
};