//https://www.geeksforgeeks.org/problems/nth-fibonacci-number1335/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
// To Find Nth Fibonacci No.

// Recursion Aprroach

class Solution {
  public:
  
  int helper(int n)
  {
      if(n==0) return 0;
      if(n==1) return 1;
      
      return helper(n-1)+ helper(n-2);
  }
  
    int nthFibonacci(int n) {
        // code here
        return helper(n);
    }
};


// Apply Dynamic Programming (Memorization)
class Solution {
  public:
  
  int helper(int n, vector<int> & dp)
  {
      if(n==0) return 0;
      if(n==1) return 1;
      
      if(dp[n] != -1) return dp[n];
      return dp[n] = helper(n-1, dp)+ helper(n-2, dp);
  }
  
    int nthFibonacci(int n) {
        // code here
        vector<int> dp(n+1, -1);
        return helper(n,dp);
    }
};


// Apply Dynamic Programming (Tabulation)
class Solution {
  public:
    int nthFibonacci(int n) {
        // code here
        vector<int> dp(n+1, -1);
        
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

// Space Optimization
class Solution {
  public:

    int nthFibonacci(int n) {
        // code here
        int prev1=0;
        int prev2=1;
        for(int i=2;i<=n;i++){
            int curr= prev1+prev2;
            prev1=prev2;
            prev2=curr;
        }
        if(n==0) return prev1;
        return prev2;
    }
};