class Solution {
public:
    const long long mod=1e9+7;

    long long modPower(long long base,long long exp,long long mod){
        if(exp==0)
            return 1;
        long long half=modPower(base,exp/2,mod);
        long long result=(half*half)%mod;
        if(exp%2==1) result=(result*base)%mod;
        return result;
    }
    int countGoodNumbers(long long n) {
       long long even_positions=(n+1)/2;
       long long odd_positions=n/2;

       long long even_part=modPower(5,even_positions,mod);
       long long odd_part=modPower(4,odd_positions,mod);

       return (even_part*odd_part)%mod;
    }
};