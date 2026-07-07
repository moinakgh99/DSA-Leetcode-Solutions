class Solution {
public:
    int tribonacci(int n) {
        int t=0,t1=0,t2=1,t3=1;
        while(n!=0){
            if(n==0){
                return t1;
            }else if(n==1){
                return t2;
            }else if(n==2){
                return t3;
            }else{
                t = t1+t2+t3;
                t1=t2;
                t2=t3;
                t3=t;
                n--;
            }
        }    
    return t;
    }
};
