//https://www.geeksforgeeks.org/problems/cutted-segments1642/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
// cut into maximum segments

//Apply Recursion
class Solution
{
    public:
    
    int helper(int n, int x, int y, int z){
        if(n==0) return 1;
        if(n<0) return 0;
        int one=1+ helper(n-x, x,y,z);
        int two=1+ helper(n-y, x,y,z);
        int three=1+ helper(n-z, x,y,z);
        
        return max(one, max(two,three));
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        return helper(n,x,y,z)-1;
    }
};


//Apply DP (Memorization)
class Solution
{
    public:
    
    int helper(int n, int x, int y, int z, vector<int>& dp){
        if(n==0) return 0;
        if(n<0){
            return INT_MIN;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int one=1+helper(n-x, x,y,z,dp);
        int two=1+helper(n-y, x,y,z,dp);
        int three=1+helper(n-z, x,y,z,dp);
        
        return dp[n]=max({one,two,three});
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> dp(n+1,-1);
        int ans=helper(n,x,y,z,dp);
        if(ans<0){
            return 0;
        }
        return ans;
        
    }
};


//