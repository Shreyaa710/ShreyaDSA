// Approach:
//     If we need to find distinct subsequences, then instead of vector we can use set.
//     And simply we can generate subsets.

class Solution {
  public:
  
    void helper(int i, int n, string& str1, set<string>& st1, string ans){
        if(i==n){
            st1.insert(ans);
            return;
        }
        
        ans+=str1[i];
        helper(i+1,n,str1,st1,ans);
        
        ans.pop_back();
        helper(i+1,n,str1,st1,ans);
    }
  
    string betterString(string str1, string str2) {
        // code here
        set<string> st1;
        set<string> st2;
        int n= str1.size();

        helper(0,n,str1, st1,"");
        helper(0,n,str2, st2,"");
        return st1.size()>= st2.size()? str1: str2;

    }
};