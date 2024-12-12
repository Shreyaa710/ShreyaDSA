//https://www.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

// Move 1 or 2 steps to reach the top of stairs

// Apply recursion
class Solution {
  public:

    int helper(int n){
        if(n==0 || n==1) return 1;
        
        return (helper(n-1)+ helper(n-2));
    }
    
    int countWays(int n) {
        // your code here
        return helper(n);
    }
};


// Apply DP (Memorization)
class Solution {
  public:
    // Function to count number of ways to reach the nth stair.
    
    int helper(int n, vector<int>& dp){
        if(n==0 || n==1) return 1;
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = ( helper(n-1,dp)+ helper(n-2, dp) );
    }
    
    int countWays(int n) {
        // your code here
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
};


//Apply DP tabulation
class Solution {
  public:

    int countWays(int n) {
        // your code here
        vector<int> dp(n+1, -1);
        dp[0]=1, dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};


//Space Optimization
class Solution {
  public:

    int countWays(int n) {
        // your code here
        vector<int> dp(n+1, -1);
        dp[0]=1, dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};