#include <bits/stdc++.h>
using namespace std;

/*
 * Function to insert an element in sorted order into a stack
 */
void sortedInsert(stack<int> &s, int x)
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

/*
 * Function to sort a stack using recursion
 */
void sortStack(stack<int> &s)
{
    if (!s.empty()) {
        // Remove top
        int x = s.top();
        s.pop();

        // Sort rest of the stack
        sortStack(s);

        // Insert top in sorted stack
        sortedInsert(s, x);
    }
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
    
    // Sort the stack
    sortStack(s);
    
    // Print the sorted stack
    cout << "Sorted stack (top to bottom): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    
    return 0;
}