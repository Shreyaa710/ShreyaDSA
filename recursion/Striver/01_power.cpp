// NOTE:
//     Power can be negative, if negative, then divide by 1 and then call recursively
//     Here, in else part recursive call for negative n is multiplied by x
//     because while calling function call will start from (n-1) i.e 1 value less.

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        if(n>0){
            double temp = myPow(x,n/2);
            if(n%2==1) return temp*temp*x;
            return temp*temp;
        }
        else{
            return 1.0/(x*myPow(x,-(long long)n-1));
        }
    }
};

// Time complexity: O(logn)
// Space complexity: O(1)