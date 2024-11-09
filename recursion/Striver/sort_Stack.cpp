// Approach:
//     Firstly, pop() each element of stack one by one and store in temp until stack become empty.
//     And now call helper for each element i.e temp and store it in correct position.


void helper(int temp, stack<int>& s)
{
    if(s.empty() || s.top()<= temp){
        s.push(temp);
        return;
    }
    
    int x=s.top();
    s.pop();
    helper(temp, s);
    s.push(x);
}

void SortedStack :: sort()
{
   //Your code here
   if(s.empty()) return;
   
   int temp=s.top();
   s.pop();
   
   sort();
   
   helper(temp, s);
}

// Time Complexity: O(n^2)
// Space Complexity: O(n)