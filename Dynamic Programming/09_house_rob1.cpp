//https://leetcode.com/problems/house-robber/

//Apply Recursion
class Solution {
public:

    int helper(int n, vector<int>& nums){
        if(n<0) return 0;
        if(n==0) return nums[0];

        int taken= nums[n] + helper(n-2, nums);
        int notTaken= helper(n-1, nums);

        return max(taken, notTaken);
    }

    int rob(vector<int>& nums) {
        int n= nums.size();

        return helper(n-1, nums);
    }
};


//Apply DP (Mmorization)
class Solution {
public:

    int helper(int n, vector<int>& nums, vector<int>& dp){
        if(n<0) return 0;
        if(n==0) return nums[0];
        if(dp[n] != -1) return dp[n];

        int taken= nums[n] + helper(n-2, nums, dp);
        int notTaken= helper(n-1, nums, dp);

        return dp[n]= max(taken, notTaken);
    }

    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n, -1);
        return helper(n-1, nums,dp);
    }
};


//Apply DP (Tabulation)
class Solution {
public:

    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n, 0);
        dp[0]= nums[0];

        for(int i=1;i<nums.size();i++){
            int taken = nums[i];
            if(i-2 >= 0) taken+= dp[i-2];
            int notTaken = dp[i-1];

            dp[i] = max(taken, notTaken);
        }

        return dp[n-1];
    }
};