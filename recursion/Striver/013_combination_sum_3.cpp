// same as combination sum 2, just we are not checking the duplicates as vector contains unique elements only.


class Solution {
public:
    void construct(int index, int k, int n, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
        if(k==0) {
            if(n==0) ans.push_back(ds);
            return;
        }

        for(int i=index;i<arr.size();i++)
        {
            if(arr[i]>n) break;
            ds.push_back(arr[i]);
            construct(i+1, k-1, n-arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
       vector<int> arr = {1,2,3,4,5,6,7,8,9};
       vector<vector<int>> ans;
       vector<int> ds;
       construct (0, k, n, arr, ans, ds) ;
       return ans;
    }
};