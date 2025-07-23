#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------
// Q1: In-Degree of Vertices in a Directed Graph
// -------------------------------------------

// 🧠 Problem: In-Degree of Vertices in a Directed Graph
// Given n directed edges in a graph where each edge goes from u to v (both are strings), calculate the in-degree for each node and print the node name and its in-degree.

// Example:
// Input: n = 3, edges = [(A, B), (B, C), (D, B)]
// Output:
// A 0
// B 2
// C 1
// D 0

// Constraints:
// - 1 <= n <= 10^5
// - u, v are strings (node names)
// - All vertices (even with in-degree 0) must be printed.

// 🔴 Approach 1 Brute Force: Count In-Degrees with Vector
// Intuition:
// Bhai, yeh toh ek tarah ka roll-call hai! Imagine you’re tracking how many times each person gets a shout-out (edge pointing to them) in a group. For each edge, you note who’s getting pointed to, and then count how many times each name appears as a target. It’s like checking a guest list multiple times to tally popularity, but it’s slow.

// Algo:
// 1. Create a vector to store all vertices and a vector to count in-degrees.
// 2. For each edge (u, v), increment the in-degree of v.
// 3. Iterate through all edges multiple times to collect unique vertices.
// 4. Print each vertex and its in-degree.

// TC: O(n^2) — multiple passes to collect vertices and count in-degrees.
// SC: O(n) — storage for vertices and in-degree counts.

// 📌 Note: Brute Force Limitations
// - Why inefficient? Repeatedly scanning edges to find unique vertices is slow.
// - Why vector? We could use a vector for simplicity, but it requires extra checks to avoid duplicates, making it less efficient than using a set or map.

void calculateInDegreeBrute(int n, vector<pair<string, string>> edges) {
    vector<string> vertices;
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++) {
        string u = edges[i].first;
        string v = edges[i].second;
        bool u_exists = false, v_exists = false;
        for (string vert : vertices) {
            if (vert == u) u_exists = true;
            if (vert == v) v_exists = true;
        }
        if (!u_exists) vertices.push_back(u);
        if (!v_exists) vertices.push_back(v);
        for (int j = 0; j < vertices.size(); j++) {
            if (vertices[j] == v) indegree[j]++;
        }
    }
    for (int i = 0; i < vertices.size(); i++) {
        cout << vertices[i] << " " << indegree[i] << endl;
    }
}

// 🔵 Approach 2 Better: Use Set for Vertices
// Intuition:
// Thodi akal lagate hain, bhai! Instead of checking vertices repeatedly, use a set to store unique nodes automatically. For each edge, increment the in-degree of the target node in a map, and use the set to list all vertices. It’s like maintaining a guest list where names are added only once, and you tally shout-outs smartly.

// Algo:
// 1. Create a set to store unique vertices and a map for in-degrees.
// 2. For each edge (u, v), insert u and v into the set and increment v’s in-degree in the map.
// 3. Iterate through the set to print each vertex and its in-degree (0 if not in map).
// 4. Return.

// TC: O(n log n) — inserting into set and map takes O(log n) per operation, n edges.
// SC: O(n) — set and map store at most O(n) vertices.

// 📌 Note: Why Set is Better
// - Set ensures unique vertices without manual duplicate checks, reducing complexity.
// - Map allows O(log n) access for in-degree updates, but still not optimal due to logarithmic overhead.

void calculateInDegreeBetter(int n, vector<pair<string, string>> edges) {
    set<string> vertices;
    map<string, int> indegree;
    for (int i = 0; i < n; i++) {
        string u = edges[i].first;
        string v = edges[i].second;
        vertices.insert(u);
        vertices.insert(v);
        indegree[v]++;
    }
    for (const string& v : vertices) {
        cout << v << " " << indegree[v] << endl;
    }
}

// 🟢 Approach 3 Optimal: Use Map and Set Efficiently
// Intuition:
// Yeh hai asli dimaag, bhai! Use a set to track all unique vertices and a map to count in-degrees in one pass. Since we’re dealing with strings, a map is perfect for direct in-degree updates, and the set ensures we print all vertices, even those with zero in-degree. It’s like having a smart ledger for shout-outs that auto-sorts names and counts.

// Algo:
// 1. Initialize a map for in-degrees and a set for vertices.
// 2. For each edge (u, v), insert u and v into the set, increment v’s in-degree in the map.
// 3. Iterate through the set, print each vertex and its in-degree from the map (0 if absent).
// 4. Return.

// TC: O(n log n) — due to set and map operations (log n for each insertion/lookup).
// SC: O(n) — for storing vertices and in-degrees.

// 📌 Note: Optimal Approach Insights
// - Why optimal? Single pass for edges, using efficient data structures (set for uniqueness, map for counts).
// - Why log n? String operations in set/map involve comparisons, leading to logarithmic complexity.
// - Edge case: Vertices with no incoming edges (e.g., A, D) have in-degree 0, handled by map’s default value.

void calculateInDegreeOptimal(int n, vector<pair<string, string>> edges) {
    map<string, int> indegree;
    set<string> vertices;
    for (int i = 0; i < n; i++) {
        string u = edges[i].first;
        string v = edges[i].second;
        vertices.insert(u);
        vertices.insert(v);
        indegree[v]++;
    }
    for (const string& v : vertices) {
        cout << v << " " << indegree[v] << endl;
    }
}

// -------------------------------------------
// Q2: Eliminated Persons in Circular Passing Game
// -------------------------------------------

// 🧠 Problem: Eliminated Persons in Circular Passing Game
// Given N people in a circle, a ball starts at person 1 and is passed K steps forward (1-based indexing, modulo logic). Mark each person who receives the ball. Stop when the ball returns to person 1. Print the numbers of people who never received the ball (or 0 if none).

// Example:
// Input: N = 6, K = 2
// Steps: 1 -> 3 -> 5 -> 1 (stop)
// Visited: {1, 3, 5}
// Output: 2 4 6
// Input: N = 5, K = 2
// Output: 0 (all visited)

// Constraints:
// - 1 <= N <= 10^5
// - 1 <= K <= 10^5

// 🔴 Approach 1 Brute Force: Simulate with Array
// Intuition:
// Bhai, yeh toh khel ka maidaan hai! Imagine kids passing a ball in a circle, and you’re noting who gets it. Start at person 1, jump K steps, mark each person, and stop when you’re back at 1. Check who’s left out. It’s like tracking a game of catch but checking every step manually.

// Algo:
// 1. Create an array to track visited persons.
// 2. Start at person 1, simulate passing the ball K steps forward using (current + K) % N.
// 3. Adjust for 1-based indexing: if current = 0, set to N.
// 4. Mark each person as visited until back at 1.
// 5. Print unvisited person numbers (or 0 if none).

// TC: O(N^2) — in worst case, we may visit many nodes before returning to 1, plus checking unvisited.
// SC: O(N) — array to track visited persons.

// 📌 Note: Brute Force Limitations
// - Why slow? Repeatedly checking the array for visited status and simulating passes can be inefficient for large N.
// - Why array? Simple to implement but doesn’t optimize for cycle detection.

void eliminatedPersonsBrute(int N, int K) {
    vector<int> visited(N + 1, 0);
    int current = 1;
    do {
        visited[current] = 1;
        current = (current + K) % N;
        if (current == 0) current = N;
    } while (current != 1);
    bool anyEliminated = false;
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            cout << i << " ";
            anyEliminated = true;
        }
    }
    if (!anyEliminated) cout << 0;
    cout << endl;
}

// 🔵 Approach 2 Better: Use Set for Visited
// Intuition:
// Thodi smartness dikhaate hain, bhai! Instead of an array, use a set to track visited people, which makes checking and inserting faster for sparse visits. Simulate the same ball-passing game, but now you’re noting unique players efficiently. It’s like keeping a VIP list for who caught the ball.

// Algo:
// 1. Create a set to track visited persons.
// 2. Start at person 1, simulate passing K steps with (current + K) % N, adjusting for 1-based indexing.
// 3. Insert each person into the set until back at 1.
// 4. Check numbers 1 to N; print those not in the set (or 0 if none).

// TC: O(N log N) — set operations (insert, find) take O(log N), and we may visit up to N nodes.
// SC: O(N) — set stores up to N visited persons.

// 📌 Note: Why Set is Better
// - Set provides O(log N) operations for checking visited status, slightly better for sparse data.
// - Still not optimal due to potential for visiting many nodes before returning to 1.

void eliminatedPersonsBetter(int N, int K) {
    set<int> visited;
    int current = 1;
    do {
        visited.insert(current);
        current = (current + K) % N;
        if (current == 0) current = N;
    } while (current != 1);
    bool anyEliminated = false;
    for (int i = 1; i <= N; ++i) {
        if (visited.find(i) == visited.end()) {
            cout << i << " ";
            anyEliminated = true;
        }
    }
    if (!anyEliminated) cout << 0;
    cout << endl;
}

// 🟢 Approach 3 Optimal: Use Vector<bool> for Efficiency
// Intuition:
// Yeh hai ultimate khel, bhai! Use a compact vector<bool> to mark visited people, minimizing memory and making checks super fast. Simulate the ball-passing with modulo logic, stop at 1, and print the unvisited. It’s like having a digital scorecard that’s quick to update and check.

// Algo:
// 1. Create a vector<bool> of size N+1 to track visited persons (1-based).
// 2. Start at person 1, simulate passing K steps with (current + K) % N, adjust if current = 0.
// 3. Mark each person as visited until back at 1.
// 4. Iterate from 1 to N, print unvisited persons (or 0 if none).

// TC: O(N) — single pass to simulate (worst case visits N nodes), single pass to print unvisited.
// SC: O(N) — vector<bool> for visited status.

// 📌 Note: Optimal Approach Insights
// - Why vector<bool>? It’s memory-efficient (1 bit per element) and faster than set for O(1) access.
// - Why modulo logic? Ensures circular movement; adjustment for current = 0 handles 1-based indexing.
// - Edge case: If K is multiple of N, cycle may be shorter, but we still check all unvisited.

void eliminatedPersonsOptimal(int N, int K) {
    vector<bool> visited(N + 1, false);
    int current = 1;
    do {
        visited[current] = true;
        current = (current + K) % N;
        if (current == 0) current = N;
    } while (current != 1);
    bool anyEliminated = false;
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            cout << i << " ";
            anyEliminated = true;
        }
    }
    if (!anyEliminated) cout << 0;
    cout << endl;
}

// -------------------------------------------
// Q3: Prime Numbers in 5-Column Table (Top-Down)
// -------------------------------------------

// 🧠 Problem: Prime Numbers in 5-Column Table (Top-Down)
// Given a number n, print all prime numbers ≤ n in a 5-column table, arranged top-down (not row-wise). Each column is filled sequentially before moving to the next.

// Example:
// Input: n = 30
// Primes: [2, 3, 5, 7, 11, 13, 17, 19, 23, 29] (10 primes)
// rows = ceil(10 / 5) = 2
// Output:
// 2 13 23
// 3 17 29
// 5 19
// 7
// 11

// Constraints:
// - 1 <= n <= 10^5

// 🔴 Approach 1 Brute Force: Check Primes with Naive Test
// Intuition:
// Bhai, yeh toh seedha hisaab hai! First, find all primes up to n by checking each number with a basic divisibility test. Then, arrange them in a 5-column table, filling each column top-down like stacking books in shelves. It’s simple but slow for big numbers.

// Algo:
// 1. Iterate from 2 to n, check if each number is prime using trial division (check divisibility up to n).
// 2. Store primes in a vector.
// 3. Calculate rows = ceil(total_primes / 5).
// 4. Print primes in a 5-column table: for each row r, print primes[c * rows + r] for columns c = 0 to 4.

// TC: O(n^2) — trial division up to n for each number.
// SC: O(n) — vector to store primes.

// 📌 Note: Brute Force Limitations
// - Why slow? Checking primality with trial division up to n is inefficient.
// - Why top-down? The problem specifies column-wise filling, so primes are distributed across columns first.

void printDoorTableBrute(int n) {
    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        bool is_prime = true;
        for (int j = 2; j <= i; ++j) {
            if (i % j == 0 && i != j) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) primes.push_back(i);
    }
    int total = primes.size();
    int rows = (total + 4) / 5;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < 5; ++c) {
            int idx = c * rows + r;
            if (idx < total) cout << primes[idx] << " ";
        }
        cout << endl;
    }
}

// 🔵 Approach 2 Better: Optimized Primality Test
// Intuition:
// Thodi smartness lagate hain, bhai! Instead of checking divisibility up to n, only check up to sqrt(n) for primality—it’s enough to catch all divisors. Then, arrange the primes in the same top-down 5-column table. It’s like sorting through a pile of numbers faster by checking fewer possibilities.

// Algo:
// 1. Iterate from 2 to n, check if each number is prime by testing divisibility up to sqrt(n).
// 2. Store primes in a vector.
// 3. Calculate rows = ceil(total_primes / 5).
// 4. Print primes in a 5-column table: for each row r, print primes[c * rows + r] for columns c = 0 to 4.

// TC: O(n * sqrt(n)) — primality test is O(sqrt(n)) for each number.
// SC: O(n) — vector to store primes.

// 📌 Note: Why sqrt(n)?
// - Checking divisibility up to sqrt(n) is sufficient because if a number has a divisor larger than its square root, it must also have a smaller divisor, which we’d already find.
// - Still not optimal for very large n due to repeated primality checks.

void printDoorTableBetter(int n) {
    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        bool is_prime = true;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) primes.push_back(i);
    }
    int total = primes.size();
    int rows = (total + 4) / 5;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < 5; ++c) {
            int idx = c * rows + r;
            if (idx < total) cout << primes[idx] << " ";
        }
        cout << endl;
    }
}

// 🟢 Approach 3 Optimal: Sieve of Eratosthenes
// Intuition:
// Yeh hai asli jugad, bhai! Use the Sieve of Eratosthenes to find all primes up to n efficiently by marking multiples of each prime as non-prime. Then, arrange them in the top-down 5-column table like a pro organizer stacking items neatly in shelves.

// Algo:
// 1. Create a boolean vector sieve of size n+1, initially true for numbers ≥ 2.
// 2. For each i from 2 to sqrt(n), if sieve[i] is true, mark all multiples (i*i, i*i+i, ...) as false.
// 3. Collect all numbers where sieve[i] is true into a primes vector.
// 4. Calculate rows = ceil(total_primes / 5).
// 5. Print primes in a 5-column table: for each row r, print primes[c * rows + r] for columns c = 0 to 4.

// TC: O(n log log n) — Sieve of Eratosthenes is highly efficient for finding primes.
// SC: O(n) — sieve vector and primes vector.

// 📌 Note: Optimal Approach Insights
// - Why Sieve? It’s the fastest way to find all primes up to n, avoiding repeated primality tests.
// - Why top-down table? The formula c * rows + r maps primes to columns first, ensuring correct order.
// - Edge case: If n < 2, no primes, so output is empty.

void printDoorTableOptimal(int n) {
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (sieve[i]) {
            for (int j = i * i; j <= n; j += i) {
                sieve[j] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (sieve[i]) primes.push_back(i);
    }
    int total = primes.size();
    int rows = (total + 4) / 5;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < 5; ++c) {
            int idx = c * rows + r;
            if (idx < total) cout << primes[idx] << " ";
        }
        cout << endl;
    }
}

// -------------------------------------------
// Main Function to Test All Problems
// -------------------------------------------
int main() {
    // Q1: In-Degree of Vertices
    cout << "Q1: In-Degree of Vertices\n";
    int n1 = 3;
    vector<pair<string, string>> edges = {{"A", "B"}, {"B", "C"}, {"D", "B"}};
    cout << "Brute:\n";
    calculateInDegreeBrute(n1, edges);
    cout << "Better:\n";
    calculateInDegreeBetter(n1, edges);
    cout << "Optimal:\n";
    calculateInDegreeOptimal(n1, edges);
    cout << endl;

    // Q2: Eliminated Persons
    cout << "Q2: Eliminated Persons\n";
    int N = 6, K = 2;
    cout << "Brute: ";
    eliminatedPersonsBrute(N, K);
    cout << "Better: ";
    eliminatedPersonsBetter(N, K);
    cout << "Optimal: ";
    eliminatedPersonsOptimal(N, K);
    cout << endl;

    // Q3: Prime Numbers Table
    cout << "Q3: Prime Numbers Table\n";
    int n3 = 30;
    cout << "Brute:\n";
    printDoorTableBrute(n3);
    cout << "Better:\n";
    printDoorTableBetter(n3);
    cout << "Optimal:\n";
    printDoorTableOptimal(n3);

    return 0;
}