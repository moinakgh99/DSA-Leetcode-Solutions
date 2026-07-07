class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        // First keep count of $5 and $10
        int five = 0, ten = 0;
        
        for(int bill : bills) {

            // Increase the count of $5 if there is any...
            if(bill == 5) five++;

            // If there is $10
            else if(bill == 10) {

                // First Check if there is any $5 left.
                if(five == 0) return false;
                five--;
                ten++;
            }

            // If there is $20
            else {

                // Prefer first $10 + $5
                if(ten > 0 && five > 0) {
                    ten--;
                    five--;
                }

                // If there is only $5 
                else if(five >= 3) five -= 3;
                
                else return false;
            }
        }
        return true;
    }
};