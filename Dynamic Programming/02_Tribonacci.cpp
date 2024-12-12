//https://www.geeksforgeeks.org/problems/tribonacci-number/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

// Summation of previous 3 numbers

//Apply recursion
class Solution {
  public:
  
  int helper(int n){
      if(n==0) return 0;
      if(n==1 || n==2) return 1;
      
      return (helper(n-1)+ helper(n-2) + helper(n-3));
  }
  
    int nthTribonacci(int n) {
        // code here
        return helper(n);
    }
};


// Apply DP (Memorization)
class Solution {
  public:
  
  int helper(int n, vector<int>& dp){
      if(n==0) return 0;
      if(n==1 || n==2) return 1;
      
      if(dp[n] != -1) return dp[n];
      return dp[n]=(helper(n-1, dp)+ helper(n-2, dp) + helper(n-3, dp));
  }
  
    int nthTribonacci(int n) {
        // code here
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
};


// Apply DP (Tablulation)
class Solution {
  public:
  
    int nthTribonacci(int n) {
        // code here
        vector<int> dp(n+1, -1);
        dp[0]=0, dp[1]=1, dp[2]=1;
        
        for(int i=3;i<=n;i++){
            dp[i]= dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
};


// Space Optimizaion
class Solution {
  public:
  
    int nthTribonacci(int n) {
        // code here
        int prev1=0, prev2=1, prev3=1;
        
        for(int i=3;i<=n;i++){
            int curr= prev1+prev2+prev3;
            prev1=prev2;
            prev2=prev3;
            prev3=curr;
        }
        
        if(n==0) return 0;
        return prev3;
    }
};