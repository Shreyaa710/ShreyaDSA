//https://www.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump

//Apply Recursion
class Solution {
  public:
  
  int helper(int n, vector<int>& arr){
      if(n<=0) return 0;
      
      int left= helper(n-1, arr) + abs(arr[n]- arr[n-1]);
      int right= helper(n-2, arr) + abs(arr[n]- arr[n-2]);
      
      return min(left,right);
  }
  
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        return helper(n-1, height);
    }
};


//Apply DP (Memorization)
class Solution {
  public:
  
  int helper(int n, vector<int>& arr, vector<int>&dp){
      if(n<=0) return 0;
      
      if(dp[n] != -1) return dp[n];
      
      int left= helper(n-1, arr,dp) + abs(arr[n]- arr[n-1]);
      int right= INT_MAX;
      if(n >1){
         right= helper(n-2, arr,dp) + abs(arr[n]- arr[n-2]);
      }
      
      return dp[n]= min(left,right);
  }
  
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n,-1);
        return helper(n-1, height, dp);
    }
};


//Apply DP (Tabulation)
class Solution {
  public:
  
  int helper(int n, vector<int>& arr, vector<int>&dp){
      if(n<=0) return 0;
      
      if(dp[n] != -1) return dp[n];
      
      int left= helper(n-1, arr,dp) + abs(arr[n]- arr[n-1]);
      int right= INT_MAX;
      if(n >1){
         right= helper(n-2, arr,dp) + abs(arr[n]- arr[n-2]);
      }
      
      return dp[n]= min(left,right);
  }
  
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n,-1);
        return helper(n-1, height, dp);
    }
};
