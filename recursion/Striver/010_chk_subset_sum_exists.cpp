// Approach:
//     If we need to chk that susbet of sum = k exists ?
//     then, we will return true whenever we got the subset with sum = k 

bool help(int i,int sum,int size,int k,vector<int>&a){
    if(i==size){
        if(sum==k) return true;

        else return false;
    }

    if(sum>k) return false;

    sum+=a[i];
    if(help(i+1,sum,size,k,a)==true) return true;
    sum-=a[i];
    if(help(i+1,sum,size,k,a)==true) return true;

    return false;

}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    // Write your code here
    bool flag=help(0,0,n,k,a);
    return flag;

}