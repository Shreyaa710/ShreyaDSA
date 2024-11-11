// Approach: 
    // First, we will add open bracket untile open<n
    //  and then close bracket until close<open


class Solution {
public:

    void helper(int i, string ans, int open, int close, vector<string>& res, int n)
    {
        if(i==2*n){
            res.push_back(ans);
            return;
        }

        if(open<n){
            ans+='(';
            helper(i+1,ans, open+1, close, res, n);
            ans.pop_back();
        }

        if(close<open){
            ans+=')';
            helper(i+1,ans,open, close+1, res, n);
            ans.pop_back();
        }
    
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(0,"",0,0,res,n);
        return res;
    }
};