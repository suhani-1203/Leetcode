class Solution {
public:
    double myPowHelper(double x,long long N){
        if(N==0) return 1;
        double half=myPowHelper(x,N/2);
        double result=half*half;
        if(N%2==1) result=result*x;
        return result;
    }
    double myPow(double x, int n) {
        long long N=n;
        if(n<0){
            x=1.0/x;
            N=-N;
        }
        return myPowHelper(x,N);
    }
};