// Ques : Any no. can be taken any no. of times, we have to generate subsets with sum == target.

// Approach:
//     Remain in same index untile arr[i] <= target. Then pop() and move to next index.


class Solution {
public:
    
    void findComb(int ind,int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
        if(ind==arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        
        if(arr[ind]<=target){
            ds.push_back(arr[ind]);
            findComb(ind,target-arr[ind],arr,ans,ds);
            ds.pop_back();
        }
        
        findComb(ind+1,target,arr,ans,ds);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        findComb(0,target,candidates,ans,ds);
        return ans;
    }
};