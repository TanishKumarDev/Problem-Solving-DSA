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
// Helper function to insert an element at the bottom of the stack
// Takes a stack reference and the element to insert
// Uses recursion to reach the bottom by removing all elements first
void insertAtBottom(stack<int> &s, int x) {
    // Base case: if stack is empty, insert element
    if (s.empty()) {
        s.push(x);
        return;
    }
    
    // Remove top element
    int temp = s.top();
    s.pop();
    // Recursively call to reach bottom
    insertAtBottom(s, x);
    // Add back the removed element
    s.push(temp);
}

// Main function to reverse a stack using recursion
// Takes a stack reference as parameter
void reverseStack(stack<int> &s) {
    // Base case: if stack is empty, return
    if (s.empty()) {
        return;
    }
    
    // Remove top element
    int x = s.top();
    s.pop();
    // Recursively reverse rest of stack
    reverseStack(s);
    // Insert removed element at bottom
    insertAtBottom(s, x);
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