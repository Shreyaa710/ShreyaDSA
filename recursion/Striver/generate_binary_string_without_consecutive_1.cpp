// Approach:
//     recursively add "0" to string (ans) until n become 0.
//     while adding 0 to string, the last index of sting doesnt matter as this will never make 2 consecutive 1s.
//     But, before adding 1 check for last index if it is not 1, then only we will add it.


class Solution{
public:

    void helper(int n, string ans, vector<string>& res)
    {
        if(n==0){
            res.push_back(ans);
            return;
        }
        
        helper(n-1,ans+"0",res);
        
        if(ans.back() != '1') helper(n-1,ans+"1",res);
    }

    vector<string> generateBinaryStrings(int num){
        //Write your code
        string ans="";
        vector<string> res;
        
        helper(num, ans, res);
        return res;
    }
};