// Approach:
//     Here, No. of even places can be calculated by n/2 + rem, and odd places by n/2.
//     From 1 to 10, 5 nos are even, 4 nos are odd. thats why function is called accordingly.
//     and simple P&C approach was applied

class Solution {
public:

    int mod= 1000000007;

    long long pow(long long x,long long n)
    {
        if(n==0) return 1;
        long long temp=pow(x,n/2);
        if(n%2==0){
            return (temp*temp)%mod;
        }

        else return (x*temp*temp)%mod;
    }

    int countGoodNumbers(long long n) {
        long long rem= n%2;
        long long even= n/2+rem;
        long long odd= n/2;

        return (pow(5,even)*pow(4,odd))%mod;
    }
};

// Time Complexity: O(logn)
// Space Complexity: O(logn)