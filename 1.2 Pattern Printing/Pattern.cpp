#include <bits/stdc++.h>
using namespace std;
// There are 4 general rules for solving a pattern-based question: 

// • We always use nested loops for printing the patterns. For the outer loop, we count the number of lines/rows and loop for them.
// • Next, for the inner loop, we focus on the number of columns and somehow connect them to the rows by forming a logic such that for each row we get the required number of columns to be printed.
// • We print the ‘*’ inside the inner loop.
// Observe symmetry in the pattern or check if a pattern is a combination of two or more similar patterns.

// Pattern 1: Square
void square(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cout << "* ";
        cout << endl;
    }
}

// Pattern 2: Right-Angled Triangle
void rightAngledTriangle(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) cout << "* ";
        cout << endl;
    }
}

// Pattern 3: Right-Angled Number Pyramid
void rightAngledNumberPyramid(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) cout << j << " ";
        cout << endl;
    }
}

// Pattern 4: Number Repeated per Row
void rightAngledNumberPyramid2(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) cout << i << " ";
        cout << endl;
    }
}

// Pattern 5: Inverted Right-Angled Triangle
void invertedRightPyramid(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = n; j > i; j--) cout << "* ";
        cout << endl;
    }
}

// Pattern 6: Inverted Right-Angled Number Pyramid
void invertedRightNumberPyramid(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = n; j > i; j--) cout << n - j + 1 << " ";
        cout << endl;
    }
}

// Pattern 7: Centered Star Pyramid
void centeredPyramid(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) cout << " ";
        for(int j = 0; j < 2 * i + 1; j++) cout << "*";
        cout << endl;
    }
}

// Pattern 8: Inverted Centered Pyramid
void invertedCenteredPyramid(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) cout << " ";
        for(int j = 0; j < 2 * (n - i) - 1; j++) cout << "*";
        cout << endl;
    }
}

// Pattern 9: Diamond
void diamondPyramid(int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i - 1; j++) cout << " ";
        for(int j = 0; j < 2 * i + 1; j++) cout << "*";
        cout << endl;
    }
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < n - i - 1; j++) cout << " ";
        for(int j = 0; j < 2 * i + 1; j++) cout << "*";
        cout << endl;
    }
}

// Pattern 10: Half Diamond
void halfDiamondPyramid(int n) {
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < n - 1; j++) cout << " ";
        for(int j = 0; j < i; j++) cout << "* ";
        cout << endl;
    }
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < n - 1; j++) cout << " ";
        for(int j = 0; j < i; j++) cout << "* ";
        cout << endl;
    }
}

int main() {
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

    return 0;
}
