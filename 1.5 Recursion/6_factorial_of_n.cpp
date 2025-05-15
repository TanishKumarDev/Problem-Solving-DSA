#include <bits/stdc++.h>
using namespace std;

// Approach & Implementation BRUTE (Recursive) - factorial of n is n times factorial of n-1
int factorial_Recursive(int n) {
    if (n == 0) return 1;
    return n * factorial_Recursive(n - 1);
}

// Approach & Implementation BETTER (Iterative) -  Mujhe 1 se n tak ke numbers ka product chahiye.
int Iterative_Iterative(int n) {
   int ans = 1;
   for(int i=1; i<=n; i++){
    ans *= i;
   }

   return ans;
}
int main() {
    int n;
    cin >> n;
    cout <<"factorial_Recursive "<< factorial_Recursive(n) << endl;
    cout << "Iterative_Iterative "<< Iterative_Iterative(n) << endl;
    return 0;
}
