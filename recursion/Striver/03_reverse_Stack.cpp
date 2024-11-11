// Approach:
//     Store element one by one in temp and call helper.
//     Now recursively reverse stack by storing element at last.

class Solution{
public:
    void helper(int temp, stack<int>& st, int size)
    {
        if(size==0){
            st.push(temp);
            return;
        }
        int x=st.top();
        st.pop();
        helper(temp,st,size-1);
        st.push(x);
    }

    void Reverse(stack<int> &St){
        int size = St.size()-1;
        while(size != 0)
        {
            int temp=St.top();
            St.pop();
            helper(temp, St, size);
            size--;
        }
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(n)