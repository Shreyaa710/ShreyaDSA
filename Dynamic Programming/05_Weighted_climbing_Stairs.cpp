//https://www.geeksforgeeks.org/problems/min-cost-climbing-stairs/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
// Minimum Cost to reach the top

//Apply Recursion
class Solution {
public:
    int helper(int n, vector<int>& cost) {
       if(n<0) return 0;
       if(n==0) return cost[0];
       
       int left= helper(n-1, cost);
       int right= helper(n-2, cost);
       
       return cost[n]+ min(left,right);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        return min(helper(n - 1, cost), helper(n - 2, cost));
    }
};


// Apply DP (Memorization)
class Solution {
public:
    int helper(int n, vector<int>& cost, vector<int> & dp) {
       if(n<0) return 0;
       if(n==0) return cost[0];
       
       if(dp[n] != -1) return dp[n];
       
       int left= helper(n-1, cost,dp);
       int right= helper(n-2, cost,dp);
       
       return dp[n]= (cost[n]+ min(left,right));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return min(helper(n - 1, cost, dp), helper(n - 2, cost, dp));
    }
};


// Apply DP (Tabulation)
int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        
        dp[0] = cost[0];
        dp[1] = cost[1];
        int left=INT_MAX, right=INT_MAX;
        for(int i=2;i<n;i++){
            left= dp[i-1] + cost[i];
            right= dp[i-2] + cost[i];
        
            dp[i] = min(left, right);
        }
        return min(dp[n-2], dp[n-1]);
    }


// Space Optimization
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        
        int prev1 = cost[0];
        int prev2 = cost[1];
        for(int i=2;i<n;i++){
            int curr= min(prev1+ cost[i], prev2+cost[i]);
            
            prev1=prev2;
            prev2=curr;
        }
        return min(prev1, prev2);
    }
};
