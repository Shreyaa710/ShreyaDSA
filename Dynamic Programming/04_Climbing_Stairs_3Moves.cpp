//https://www.geeksforgeeks.org/count-ways-reach-nth-stair-using-step-1-2-3/

// Apply recursion
#include <bits/stdc++.h>
using namespace std;

int helper(int n)
{
    if(n==0) return 1;
    if(n<0) return 0;
    
    return (helper(n-1) + helper(n-2) + helper(n-3));
}

int main() {
    int n=4;
    cout<< helper(n);
}

// Apply DP (Memorization)
#include <bits/stdc++.h>
using namespace std;

int helper(int n, vector<int>& dp)
{
    if(n==0) return 1;
    if(n<0) return 0;
    
    if(dp[n] != -1) return dp[n];
    return dp[n]= (helper(n-1,dp) + helper(n-2,dp) + helper(n-3,dp));
}

int main() {
    int n=4;
    vector<int> dp(n+1, -1);
    cout<< helper(n, dp);
}


// Apply DP (Tabulation)
