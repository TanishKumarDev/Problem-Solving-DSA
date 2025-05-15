#include <bits/stdc++.h>
using namespace std;

int main() {
    string dominoes;
    cin >> dominoes;
    int n = dominoes.size();

    // BRUTE FORCE: TC - O(n^2) SC - O(1)
    // Approach: Iterate for each 'R' and 'L' and simulate their effect on the dominoes.
    // Update the result string as we process each domino one by one.
    string res = dominoes;

    // BRUTE FORCE Solution
    for (int i = 0; i < n; ++i)
    {
        if (dominoes[i] == 'R')
        {
            int j = i + 1;
            while (j < n && dominoes[j] == '.')
            {
                // Handle collision with 'L'
                if (j + 1 < n && dominoes[j + 1] == 'L')
                    break;
                res[j] = 'R';
                j++;
            }
        }
        else if (dominoes[i] == 'L')
        {
            int j = i - 1;
            while (j >= 0 && dominoes[j] == '.')
            {
                // Handle collision with 'R'
                if (j - 1 >= 0 && dominoes[j - 1] == 'R')
                    break;
                res[j] = 'L';
                j--;
            }
        }
    }

    cout << "Brute Force Result: " << res << endl;

    // 🔍 Issues:
    // 1. Multiple positions for each 'R' or 'L' are updated — O(n²)
    // 2. Collisions need to be manually handled.
    // 3. Not efficient for large strings.

    // ================================================================================

    // BETTER APPROACH (Two Pointers) - Key Idea: Treat the sequence between 'R' and 'L' and balance the forces from both sides.
    // This approach is a bit messy and hard to generalize, so we'll directly proceed to the optimized solution.
    
    // ================================================================================

    // Optimized Approach: TC - O(n) SC - O(n)
    // Key Idea: Use a force array to simulate the forces acting on each domino, one from left to right, and the other from right to left.
    // This approach is efficient, runs in linear time, and handles the problem in O(n).

    vector<int> forces(n, 0);  // Forces array to store force values for each domino.
    
    // Left to Right pass for 'R'
    int force = 0;
    for (int i = 0; i < n; ++i)
    {
        if (dominoes[i] == 'R')
        {
            force = n;  // Maximum force for 'R'.
        }
        else if (dominoes[i] == 'L')
        {
            force = 0;  // Reset force when 'L' is encountered.
        }
        else
        {
            force = max(force - 1, 0);  // Reduce force for '.' as it falls.
        }
        forces[i] += force;  // Store the computed force for the current domino.
    }

    // Right to Left pass for 'L'
    force = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        if (dominoes[i] == 'L')
        {
            force = n;  // Maximum force for 'L'.
        }
        else if (dominoes[i] == 'R')
        {
            force = 0;  // Reset force when 'R' is encountered.
        }
        else
        {
            force = max(force - 1, 0);  // Reduce force for '.' as it falls.
        }
        forces[i] -= force;  // Subtract the force for the current domino from the left-to-right pass.
    }

    // Final result construction
    string result = "";
    for (int f : forces)
    {
        if (f > 0)
            result += 'R';  // If force > 0, the domino falls to the right.
        else if (f < 0)
            result += 'L';  // If force < 0, the domino falls to the left.
        else
            result += '.';  // If force == 0, the domino stays upright.
    }

    // Output the final result
    cout << "Optimized Result: " << result << endl;

    return 0;
}

/*
==================================================================================

Approach Breakdown:

1. **Brute Force Approach**:
   - Time Complexity: O(n²)
   - Space Complexity: O(1)
   - Approach: For each domino ('R' or 'L'), we try to simulate its effect on the adjacent dominoes.
   - We manually update the positions for the falling dominoes one by one, which leads to an inefficient solution for large inputs.

2. **Better Approach (Two Pointers)**:
   - This approach focuses on balancing the forces between 'R' and 'L'. 
   - However, implementing this solution in code is more complex and difficult to generalize for all edge cases.
   - Therefore, we proceed with the final **Optimized Approach**.

3. **Optimized Approach**:
   - Time Complexity: O(n) (Two linear passes)
   - Space Complexity: O(n) (Storing forces array)
   - Approach: 
     - We first perform a left-to-right pass to propagate the 'R' forces.
     - Then, we perform a right-to-left pass to propagate the 'L' forces.
     - The final forces array is used to determine the final state of each domino: whether it falls left ('L'), right ('R'), or stays upright ('.').

     	✅ Approach Recap (Desi Style):
		1. Ek forces[] array banayenge size = n
		2. Pehle left to right pass karenge:
			○ Jab 'R' mile toh force = n (max)
			○ Jab '.' mile toh force-- (agar > 0 ho)
			○ Jab 'L' mile toh force = 0
			○ Is force ko forces[i] mein store karenge
		3. Ab right to left pass:
			○ Jab 'L' mile toh force = n (max)
			○ Jab '.' mile toh force-- (agar > 0 ho)
			○ Jab 'R' mile toh force = 0
			○ Ab forces[i] -= force (kyunki yeh negative hai)
		4. Last loop mein:
			○ force > 0 → 'R'
			○ force < 0 → 'L'
            else → '.'
==================================================================================
*/
