//Ques: Find subsets with sum == target. Condition: Each element should be taen once and subsets cannot be duplicate.

// Approach:
//     First, sort the array so that duplicates can be neglected.
//     We will take the arr[i] element until arr[i]>target, and if this condn reaches we will come out of the loop which will prevent
//     further checking .

class Solution {
public:

    void helper(int ind,int target,int n, vector<int>& arr, vector<vector<int>>& res, vector<int>& ans){
        if(target==0){
            res.push_back(ans);
        }

        for(int i=ind;i<n;i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            ans.push_back(arr[i]);
            helper(i+1,target-arr[i],n,arr,res,ans);
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> ans;
        int n= candidates.size();
        helper(0, target, n, candidates, res, ans);
        return res;
    }
};