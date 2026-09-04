class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count_5 = 0, count_10 = 0;

        for(int x : bills) {
            if(x == 5) count_5++;  // khaali 5 rupees h to

            else if(x == 10) {  // agar 10 rupees diye
                if(count_5 > 0) {  // pehle check krenga ki 5 rupees h ?
                    count_5--;
                    count_10++;
                } else return false;
            }

            else {  // agar 20 rupees diye ....
                if(count_5 > 0 && count_10 > 0) { // agar 5 and 10 rupees dono h to !!
                    count_5--;
                    count_10--;
                }
                else if(count_5 >= 3) count_5 -= 3;  // if 5 rupees 3 se zyaada h to !!
                else return false;
            }
        }

        return true;
    }
};