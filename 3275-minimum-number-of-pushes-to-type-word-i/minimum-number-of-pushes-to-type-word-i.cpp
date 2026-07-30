class Solution {
public:
    int minimumPushes(string word) {

        // Approach 1 .....
        // int n = word.size();
        // int push = 0;

        /*
            Agar pos 1 h to , ek baar press krna padega, 2 h to 2 baar press krna h and so on ...
            har element ko ek position assign krdi h, agar saare pos fill hogyi to, dubara starting se fill krna h, 
            to pos +1 krka, jo remaining length k basis p push krdenga !!!
        */
        // int pos = 1;
        // while(n > 0) {
        //     if(n >= 8) push += 8 * pos;
        //     else push += n * pos;

        //     pos++;
        //     n -= 8;
        // }

        // return push;


        // Approach 2 .... By storing the frequencies
        vector<int> freq(26, 0);
        for(auto &ch : word) freq[ch - 'a']++;

        sort(freq.begin(), freq.end(), greater<>{});
        
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