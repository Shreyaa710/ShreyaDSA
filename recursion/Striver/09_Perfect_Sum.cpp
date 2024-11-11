// Approach: 
//     DP is used in this question.
//     We are finding no. of subsets sum equal to target. 
//     So we can simply go for pick not pick approach while checking arr[i] <= target.

class Solution{

	public:
	
	int mod=1000000007;
	int helper(int i, int arr[], vector<vector<int>>& dp,int target)
	{
	    if(i==0){
	        if(target==0 && arr[0]==0) return 2;
	        
	        if(target==0 || target== arr[0]) return 1;
	        
	        return 0;
	    }
	    if(dp[i][target] != -1) return dp[i][target];
	  
	    int notTaken= helper(i-1, arr, dp, target);
	    
	    int taken=0;
	    if(arr[i]<=target){
	        taken= helper(i-1,arr, dp, target -arr[i]);
	    }
	    
	    return dp[i][target]= (taken+notTaken)%mod;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n, vector<int>(sum+1,-1));
         return helper(n-1, arr,dp , sum)%mod;
   
	}
	  
};