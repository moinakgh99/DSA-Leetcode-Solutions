class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int n = nums.size();
        
        // Using O(n) space ..
        // unordered_map<int,int> mp;
        // for(int x : nums) mp[x]++;

        // for(auto &it : mp) if(it.second == 1) return it.first;
        // return -1;


        // Using O(1) space ...

        /*
        Things to know : 
        1) Left Shift : "<<"   , ex : temp = 1 << 2  -> left me do baar bits shift krdo
        here 1 : 000001 -> 2 left shifts -> 000100 -> becomes 4 -> temp stores 4

        2) How to find if kth char is 0 or 1 ???
        ex: num = 7 -> 0000111 -> 4th bit ky h ? ye btao ?
            step 1 : temp = 1 << k;  -> 1 k kth time left krdo
            step 2 : if(num && temp == 0)  then kth bit 0 h 
                    else kth bit 1 h !!

        3) OR : Agar kisi position k kth bit 1 krna h to OR lelo ...
            ex: 7 k 2 bit 1 krna h !! , to 1 << 2(kth) then OR with num ... 
        */

        int res = 0;
        for(int k = 0; k <= 31; k++) {
            int temp = (1 << k);
            int countOne = 0, countZero = 0;
            for(int &x : nums) {
                if((x & temp) == 0) countZero++;
                else countOne++;
            }

            if(countOne % 3 == 1) res = (res | temp);
        }
        return res;
    }
};