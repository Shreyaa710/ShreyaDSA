//Approach:
//     Whenever we need to generate subsets :- Simply do Pick, not pick
//     This will not generate unique subsets

class Solution {
public:
    
    void helper(vector<int> &v, int i, vector<int>&subset,vector<vector<int>> &ans){
        if(v.size()==i){
            ans.push_back(subset);
            return;
        }
        
        subset.push_back(v[i]);
        helper(v,i+1,subset,ans);
        
        subset.pop_back();
        helper(v,i+1,subset,ans);
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        helper(nums,0,subset,ans);
        return ans;
    }
};

// Time Complexity: O(2^n)
// Space Complexity: O(N)