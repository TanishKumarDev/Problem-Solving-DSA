#include <bits/stdc++.h>
using namespace std;
/*
// There are 4 general rules for solving a pattern-based question:

    - We always use nested loops for printing the patterns. For the outer loop, we count the number of lines/rows and loop for them.
    - Next, for the inner loop, we focus on the number of columns and somehow connect them to the rows by forming a logic such that for each row we get the required number of columns to be printed.
    - We print the ‘*’ inside the inner loop.
    - Observe symmetry in the pattern or check if a pattern is a combination of two or more similar patterns.
*/

// Pattern 1: Square
void square(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << "* ";
        cout << endl;
    }
}

// Pattern 2: Right-Angled Triangle
void rightAngledTriangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << "* ";
        cout << endl;
    }
}

// Pattern 3: Right-Angled Number Pyramid
void rightAngledNumberPyramid(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << j << " ";
        cout << endl;
    }
}

// Pattern 4: Number Repeated per Row
void rightAngledNumberPyramid2(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            cout << i << " ";
        cout << endl;
    }
}

// Pattern 5: Inverted Right-Angled Triangle
void invertedRightPyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
            cout << "* ";
        cout << endl;
    }
}

// Pattern 6: Inverted Right-Angled Number Pyramid
void invertedRightNumberPyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > i; j--)
            cout << n - j + 1 << " ";
        cout << endl;
    }
}

// Pattern 7: Centered Star Pyramid
void centeredPyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
            cout << " ";
        for (int j = 0; j < 2 * i + 1; j++)
            cout << "*";
        cout << endl;
    }
}

// Pattern 8: Inverted Centered Pyramid
void invertedCenteredPyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            cout << " ";
        for (int j = 0; j < 2 * (n - i) - 1; j++)
            cout << "*";
        cout << endl;
    }
}

// Pattern 9: Diamond
void diamondPyramid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
            cout << " ";
        for (int j = 0; j < 2 * i + 1; j++)
            cout << "*";
        cout << endl;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n - i - 1; j++)
            cout << " ";
        for (int j = 0; j < 2 * i + 1; j++)
            cout << "*";
        cout << endl;
    }
}

// Pattern 10: Half Diamond
void halfDiamondPyramid(int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < n - 1; j++)
            cout << " ";
        for (int j = 0; j < i; j++)
            cout << "* ";
        cout << endl;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < n - 1; j++)
            cout << " ";
        for (int j = 0; j < i; j++)
            cout << "* ";
        cout << endl;
    }
}

// Pattern 11: binary triangle
void binaryTrianle(int n)
{
    // First row starts by printing a single 1.
    int start = 1;

    for (int i = 0; i < n; i++)
    {

        if (i % 2 == 0)
            start = 1;

        else
            start = 0;
        for (int j = 0; j <= i; j++)
        {
            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }
}

// Pattern 12: Number Crown
void numberCrown(int n)
{
    for (int i = 0; i <= n; i++)
    {
        // Printing number
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }

        // Printing space
        // 2*(n-i) is used to calculate the number of spaces needed to be printed before the next set. If we used 2*(n-i) instead, we’d get a space in the middle even on the last line, which would break the symmetry.
        for (int j = 0; j < 2 * (n - i); j++)
        {
            cout << " ";
        }
        // Printing number
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
    }
}

// Pattern 13: Increasing Number Triangle
void increaseNumberTriangle(int n)
{
    int num = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num << " ";
            num = num + 1;
        }
        cout << endl;
    }
}

// Pattern 14: Increasing Letters Triangle
void increaseLettersTriangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        // 'A' + i controls how far the character loop runs in each row. ensures that each row prints one more letter than the last.
        for (char ch = 'A'; ch <= 'A' + i; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

// Pattern 15: Reverse Letters Triangle
void reverseLettersTriangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + (n - i - 1); ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

// Pattern 16: Alpha Ramp
void alphaRamp(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'A' + i;
        for (int j = 0; j <= i; j++)
        {
            cout << ch;
        }
        cout << endl;
    }
}

// Pattern 17: alphaHill
/*
// intuition:
1.Obseravtion -> increasing then decreasing alphabets.
2. 2*i + 1 → Total Characters Per Row
    - Har row me odd number of characters hote hain.
    - Left side increasing + right side decreasing.
    For row i:
    - Increase → i + 1 chars
    - Decrease → i chars
    - Total = i + 1 + i = 2*i + 1
3. breakpoint = (2*i + 1) / 2 → Middle Position
    - Yeh middle index batata hai jahan tak ch++ karna hai.
    - Uske baad ch-- hota hai.
    - Example (i = 2): ABCBA
4. Har row ek symmetric alphabet pyramid hoti hai:
    - left half (A to peak) → ch++
    - right half (peak to A) → ch--
    - Breakpoint divides both parts.
*/
void alphaHill(int n)
{
    for (int i = 0; i < n; i++)
    {

        // spaces before the alphabets
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        // printing alphabets in hill shape
        char ch = 'A';
        int breakpoint = (2 * i + 1) / 2;
        for (int j = 1; j <= 2 * i + 1; j++)
        {
            cout << ch;
            if (j <= breakpoint)
                ch++;
            else
                ch--;
        }

        // move to next line after row is complete
        cout << endl;
    }
}

// Pattern 18: Alpha Triangle
/*
    // Intuitions:
    1. starting at different point each row ((A + n - 1) - i).
    2. go up to the same last character (A + n - 1).
*/
void alphaTriangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = ('A' + n - 1) - i; ch <= ('A' + n - 1); ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

// Pattern 19: symmetricVoid
/*
// intuition:

1. observe the pattern:  TOTAL ROWS = 2 × n. n = 6, so rows = 12. The pattern is symmetrical vertically:
2. First Half (0 to n - 1): Decrease stars on each side, increase space in the middle
    - Left stars: n - i
    - Spaces in middle: 2 * i
    - Right stars: n - i
3.  Second Half (n to 2n - 1): Increase stars on each side, decrease middle space
    Let k = i - n (0-based index for the lower half)
    For each k from 0 to n - 1:

    - Left stars: k + 1
    - Spaces: 2 * (n - k - 1)
    - Right stars: k + 1
*/
void symmetricVoid(int n)
{
    // Upper half
    for (int i = 0; i < n; i++)
    {
        int stars = n - i;
        int spaces = 2 * i;

        // Left stars
        for (int j = 0; j < stars; j++)
            cout << "*";

        // Spaces
        for (int j = 0; j < spaces; j++)
            cout << " ";

        // Right stars
        for (int j = 0; j < stars; j++)
            cout << "*";

        cout << endl;
    }

    // Lower half
    for (int i = 0; i < n; i++)
    {
        int stars = i + 1;
        int spaces = 2 * (n - i - 1);

        // Left stars
        for (int j = 0; j < stars; j++)
            cout << "*";

        // Spaces
        for (int j = 0; j < spaces; j++)
            cout << " ";

        // Right stars
        for (int j = 0; j < stars; j++)
            cout << "*";

        cout << endl;
    }
}

// Pattern 20: symmetricButterfly
/*
// Intuition:
1. Observe the pattern:
    - The butterfly is symmetrical vertically and horizontally:
    - Top half: Increases stars, decreases spaces
    - Bottom half: Mirrors the top half
2. Think of it as two halves: Top half and bottom half.
    - For row i (1 to n):

        - Left stars: i
        - Spaces: 2*(n - i)
        - Right stars: i

    - For row i (n down to 1):

        - Just mirror the top half logic: Jo pattern top half mein banaya hai (rows 0 to n-1), usko bottom half mein reverse order mein print karo.
        Mirror ka kya matlab hai?
        - Top half mein: i jaata hai 0 se n-1 tak → stars badhte hain, spaces ghatte hain.- Bottom half mein: i ko reverse mein chalao: n-1 se 0 tak → wahi logic repeat hoga, lekin ulta order mein.
*/
void symmetricButterfly(int n)
{
    // Upper half
    for (int i = 0; i < n; i++)
    {
        int stars = i + 1;
        int spaces = 2 * (n - i - 1); // FIXED: Off-by-one

        // Left stars
        for (int j = 0; j < stars; j++)
            cout << "*";

        // Spaces
        for (int j = 0; j < spaces; j++)
            cout << " ";

        // Right stars
        for (int j = 0; j < stars; j++)
            cout << "*";

        cout << endl;
    }

    // Lower half
    for (int i = n - 1; i >= 0; i--)
    {
        int stars = i + 1;
        int spaces = 2 * (n - i - 1);

        // Left stars
        for (int j = 0; j < stars; j++)
            cout << "*";

        // Spaces
        for (int j = 0; j < spaces; j++)
            cout << " ";

        // Right stars
        for (int j = 0; j < stars; j++)
            cout << "*";

        cout << endl;
    }
}

// Pattern 21: hollowRectangle
/*
// Intuition
    - The pattern forms a rectangle of stars with:
    - Full stars on first and last row
    - Stars only at the boundaries in middle rows
    - Spaces in the center of middle rows

// Pattern Observation
    Let’s say N = 6

    Rows = N
    Columns = N (you can modify for MxN rectangles too)

    Loop through each row i from 0 to N-1:
    If i == 0 or i == N-1: Print full stars (row border)
        Else: Print *, then (N-2) spaces, then *

Why (n-2)?
    Total columns = n

    - On each middle row, the first and last columns are stars (*).
    - So, the remaining columns inside (between the stars) = n - 2
    - These are filled with spaces to create the hollow effect.
*/
void hollowRectangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        // First or last row: print all stars
        if (i == 0 || i == n - 1)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "*";
            }
        }
        // Middle rows: print star, spaces, star
        else
        {
            cout << "*"; // left border
            for (int j = 0; j < n - 2; j++)
            {
                cout << " ";
            }
            cout << "*"; // right border
        }
        cout << endl;
    }
}

// Pattern 22: The Number Pattern
/*
// Intuition
    Given N, print a square of size (2*N - 1) × (2*N - 1).

    - The outermost layer contains N
    - The next inner layer contains N-1
    - The next inner layer contains N-2, and so on...
    - The center of the square contains 1
    - This pattern forms concentric layers of decreasing numbers moving inward.

// Example for N = 3
    Size = 5 × 5 (2*3-1 = 5)

// How to find the number at position (i, j)?
- The distance of (i, j) from the edges defines the number printed.
- Calculate the minimum distance to any border: top, bottom, left, right

    Number at (i, j) = N - min(distance to any border)

    Where:
    distance to top = i
    distance to left = j
    distance to bottom = size-1 - i
    distance to right = size-1 - j


// Pattern Observatio
    Let’s say N = 6
    - Rows = N
    - Columns = N (you can modify for MxN rectangles too)

    Loop through each row i from 0 to N-1:
    For each column j from 0 to N-1:
    Print the number N - min(i, j)
*/
void numberPattern(int N)
{
    int size = 2 * N - 1;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int top = i;
            int left = j;
            int bottom = size - 1 - i;
            int right = size - 1 - j;

            int min_dist = min(min(top, bottom), min(left, right));
            cout << N - min_dist << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    square(n);
    rightAngledTriangle(n);
    rightAngledNumberPyramid(n);
    rightAngledNumberPyramid2(n);
    invertedRightPyramid(n);
    invertedRightNumberPyramid(n);
    centeredPyramid(n);
    invertedCenteredPyramid(n);
    diamondPyramid(n);
    halfDiamondPyramid(n);
    binaryTrianle(n);
    numberCrown(n);
    increaseNumberTriangle(n);
    alphaRamp(n);
    alphaHill(n);
    alphaTriangle(n);
    symmetricVoid(n);
    symmetricButterfly(n);
    hollowRectangle(n);
    numberPattern(n);

    return 0;
}
