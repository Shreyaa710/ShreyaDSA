//https://www.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost

//Minimum cost to reach top of the stair

//Apply Recursion
class Solution {
  public:
  
    int helper(int n, int k, vector<int>& arr){
        if(n==0) return 0;
        int mini=INT_MAX;
        for(int i=1;i<=k;i++){
            if(n-i>=0){
                mini= min(mini, helper(n-i, k, arr) + abs(arr[n]- arr[n-i]));
            }
        }
        return mini;
    }
  
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        
        return helper(arr.size()-1, k, arr);
    }
};


//Apply DP (Memorization)
class Solution {
  public:
  
    int helper(int n, int k, vector<int>& arr, vector<int>& dp){
        if(n==0) return 0;
        
        if(dp[n] != -1) return dp[n];
        
        int mini=INT_MAX;
        for(int i=1;i<=k;i++){
            if(n-i>=0){
                mini= min(mini, helper(n-i, k, arr,dp) + abs(arr[n]- arr[n-i]));
            }
        }
        return dp[n] = mini;
    }
  
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        vector<int> dp(arr.size(),-1);
        return helper(arr.size()-1, k, arr,dp);
    }
};


//Apply Tabulation
class Solution {
  public:

    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        vector<int> dp(arr.size(),-1);
        dp[0]=0;
        for(int i=1;i<arr.size();i++){
            int mini= INT_MAX;
            for(int j=1;j<=k;j++){
                if(i-j >= 0){
                    mini= min(mini,dp[i-j]+ abs(arr[i]-arr[i-j]));
                }
            }
            
            dp[i]= mini;
        }
        
        return dp[arr.size()-1];
    }
};