#include <bits/stdc++.h>
using namespace std;

/*
Intuition:

Remove everything using recursion, then insert each one back — but this time, at the bottom instead of top.
This flips the order and reverses the stack.

Time and Space Complexity:

Time: O(n^2) → each insertAtBottom takes O(n) time, called n times.
Space: O(n) → for recursion call stack.

*/

/*
 * Function to insert an element in sorted order into a stack
 */
void insertAtBottom(stack<int> &s, int x)
{
    if(s.empty() || s.top() < x)
    {
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();

    sortedInsert(s, x);

    s.push(temp);
}



int main()
{
    // Create a stack
    stack<int> s;
    
    // Push elements in reverse order (5 will be at top) 
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    
    // stack =  1 2 3 4 5

    // Reverse the stack
    reverseStack(s);
    
    // Print the sorted stack
    cout << "Sorted stack (top to bottom): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    
    return 0;
}