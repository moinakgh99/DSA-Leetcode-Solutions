class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) {
            return false;
        }
        else{
        while(n%2==0) {
            n=n/2;
        }
        if(n==1) return true;
        else return false;
    } }
};