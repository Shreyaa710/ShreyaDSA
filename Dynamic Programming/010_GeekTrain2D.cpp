//https://www.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training


//Apply Recursion
class Solution {
  public:
  
  int helper(int row, int last, vector<vector<int>>& arr){
      
      if(row==0){
          int m=INT_MIN;
          for(int i=0;i<3;i++){
              if(i!= last) m=max(m, arr[0][i]);
          }
          return m;
      }
      
      int maxi=INT_MIN;
      for(int i=0;i<3;i++){
          if(i!= last){
              int temp= arr[row][i] + helper(row-1, i, arr);
              maxi=max(maxi, temp);
          }
      }
      return maxi;
  }
  
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        return helper(n-1, 3, arr);
    }
};


//Apply DP (Memorization)
class Solution {
  public:
  
  int helper(int row, int last, vector<vector<int>>& arr, vector<vector<int>>& dp){
      
      if(row==0){
          int m=INT_MIN;
          for(int i=0;i<3;i++){
              if(i!= last) m=max(m, arr[0][i]);
          }
          return m;
      }
      
      if(dp[row][last]!= -1) return dp[row][last];
      
      int maxi=INT_MIN;
      for(int i=0;i<3;i++){
          if(i!= last){
              int temp= arr[row][i] + helper(row-1, i, arr,dp);
              maxi=max(maxi, temp);
          }
      }
      return dp[row][last]= maxi;
  }
  
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return helper(n-1, 3, arr, dp);
    }
};


//Apply DP (Tabulation)
