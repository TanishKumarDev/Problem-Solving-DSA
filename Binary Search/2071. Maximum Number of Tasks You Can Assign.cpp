#include <bits/stdc++.h>
using namespace std;

// 🧠 Optimal Solution Intuition (Line by Line)
// Top k strongest workers uthao, kyunki humein sirf k tasks assign karne hain.
// Sabse hard k tasks se shuru karo, kyunki unhe sabse zyada strength chahiye hoti hai.
// Sabse strong available worker uthao multiset ke end se.
// Agar worker ki strength task se zyada ya barabar hai, toh seedha assign kar do.
// Agar worker task nahi kar sakta aur koi pill bhi nahi bachi, toh return false (assignment possible nahi).
// Ab dhoondo aisa weakest possible worker jise pill dekar task complete karwaya jaa sake.
// Agar aisa koi worker hi nahi mila, toh bhi assignment possible nahi — return false.
// Agar mila, toh pill use karo, task assign karo, aur us worker ko hata do.
// Tasks aur workers dono ko sort karo strength ke increasing order mein.
// Ab binary search lagao 0 se min(tasks.size(), workers.size()) ke beech.
// mid ka matlab hai: "kya hum mid tasks assign kar sakte hain?"
// Agar mid possible hai, toh aur zyada try karo → low = mid + 1.
// Agar mid possible nahi, toh kam try karo → high = mid - 1.
// Loop ke baad, ans mein max number of assignable tasks aa jaayega.
bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
    multiset<int> avail(workers.end() - k, workers.end());  // Strongest k workers
    int pillsLeft = pills;

    for (int i = k - 1; i >= 0; --i) {  // Start from hardest task
        auto it = prev(avail.end());   // Get strongest available worker

        if (*it >= tasks[i]) {
            avail.erase(it);  // Worker can do task directly
        } else {
            if (pillsLeft == 0) return false;  // No pills left and can't assign

            // Find weakest worker who can do it with pill
            auto usePill = avail.lower_bound(tasks[i] - strength);
            if (usePill == avail.end()) return false;

            avail.erase(usePill);
            pillsLeft--;
        }
    }

    return true;
}

int maxTasks(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
    sort(tasks.begin(), tasks.end());       // Easy → Hard
    sort(workers.begin(), workers.end());   // Weak → Strong

    int low = 0, high = min((int)tasks.size(), (int)workers.size()), ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canAssign(mid, tasks, workers, pills, strength)) {
            ans = mid;
            low = mid + 1;  // Try for more
        } else {
            high = mid - 1;  // Try less
        }
    }

    return ans;
}
