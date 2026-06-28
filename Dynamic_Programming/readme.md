# Dynamic Programming

## What is Dynamic Programming?

Dynamic Programming (DP) is an optimization technique used to solve complex problems by breaking them into **overlapping subproblems**, solving each subproblem only once, and storing the results to avoid repeated computation.

**Core Idea:** If a problem has:

* **Optimal Substructure** — the optimal solution can be built from optimal solutions of smaller subproblems.
* **Overlapping Subproblems** — the same subproblems are solved multiple times.

Then DP can significantly reduce the time complexity by reusing previously computed results.

```text
Time Complexity:  O(n²) or O(n³) depending on the problem
Space Complexity: O(n) or O(n²) for the DP table
```

> **Progress:** 30 problems solved across 5 major DP patterns.

---

# How to Identify a DP Problem

```text
Does the problem ask for:
├── Count the number of ways?         → DP (usually)
├── Minimum / Maximum of something?   → DP (usually)
├── Is it possible (True / False)?    → DP (usually)
└── Find the Longest / Shortest?      → DP (usually)

AND does it have:
├── Overlapping subproblems?          → Memoization helps
└── Optimal substructure?             → DP applies
```

> **Rule of Thumb:** If the brute-force solution is exponential and repeatedly solves the same states, Dynamic Programming is probably the right approach.

---

# Three Steps to Solve Any DP Problem

```text
Step 1 — Recursive (Brute Force)
         Write the plain recursive solution.
         Identify the recurrence and base cases.
                    ↓
Step 2 — Memoization (Top-Down)
         Store answers in a DP table.
         Return cached results whenever possible.
                    ↓
Step 3 — Tabulation (Bottom-Up)
         Convert recursion into iteration.
         Build the DP table from base cases upward.
         Optimize space whenever possible.
```

---

# Common Off-by-One Pitfalls

| Mistake                                | Fix                                               |
| -------------------------------------- | ------------------------------------------------- |
| Wrong base case                        | Dry run with `n = 0` and `n = 1`                  |
| Forgetting to initialize DP table      | Initialize with `-1` before memoization           |
| String index mismatch                  | Shift indices if DP is 1-indexed                  |
| Mixing item index and capacity index   | Keep loop meanings consistent                     |
| Printing solution without backtracking | Trace through the DP table instead of recomputing |

---

# DP Patterns

---

# Pattern 1 — 0/1 Knapsack

### When to use

You have **N items**, each with a **weight** and **value**, along with a capacity **W**.

Each item can be chosen **at most once**.

### Key Insight

At every item, you have exactly two choices:

* Take the item
* Leave the item

Taking an item decreases the remaining capacity, while leaving it simply moves to the next item.

This simple **take-or-leave** decision forms the basis of many problems.

```cpp
// 0/1 Knapsack — Memoization
int knapsack(int W, vector<int>& wt, vector<int>& val,
             int n, vector<vector<int>>& dp) {

    if (n == 0 || W == 0)
        return 0;

    if (dp[n][W] != -1)
        return dp[n][W];

    if (wt[n-1] <= W)
        return dp[n][W] = max(
            val[n-1] + knapsack(W - wt[n-1], wt, val, n-1, dp),
            knapsack(W, wt, val, n-1, dp)
        );

    return dp[n][W] = knapsack(W, wt, val, n-1, dp);
}
```

### Problems

| # | Problem                                           | Difficulty |
| - | ------------------------------------------------- | ---------- |
| 1 | 0/1 Knapsack (Recursive → Memoization → Top Down) | 🟡 Medium  |
| 2 | Subset Sum Problem                                | 🟡 Medium  |
| 3 | Equal Sum Partition                               | 🟡 Medium  |
| 4 | Count of Subsets with Given Sum                   | 🟡 Medium  |
| 5 | Minimum Subset Sum Difference                     | 🔴 Hard    |
| 6 | Count Subsets with Given Difference               | 🟡 Medium  |
| 7 | Target Sum (LC 494)                               | 🟡 Medium  |

---

# Pattern 2 — Unbounded Knapsack

### When to use

Each item can be picked **unlimited times**.

### Key Insight

The only difference from 0/1 Knapsack:

* **Take → stay on the same item**
* **Leave → move to the previous item**

```cpp
if (wt[n-1] <= W)
    return dp[n][W] = max(
        val[n-1] + knapsack(W - wt[n-1], wt, val, n, dp),
        knapsack(W, wt, val, n-1, dp)
    );
```

### Problems

| # | Problem                              | Difficulty |
| - | ------------------------------------ | ---------- |
| 1 | Unbounded Knapsack                   | 🟡 Medium  |
| 2 | Rod Cutting                          | 🟡 Medium  |
| 3 | Coin Change — Maximum Ways           | 🟡 Medium  |
| 4 | Coin Change — Minimum Coins (LC 322) | 🟡 Medium  |

---

# Pattern 3 — Longest Common Subsequence (LCS)

### When to use

Whenever **two strings or sequences** are involved and you're asked to compare, transform, or find similarities.

### Key Insight

Compare characters:

* Match → move both pointers
* Don't match → skip one character from either string

```cpp
int lcs(string& a, string& b, int m, int n,
        vector<vector<int>>& dp) {

    if (m == 0 || n == 0)
        return 0;

    if (dp[m][n] != -1)
        return dp[m][n];

    if (a[m-1] == b[n-1])
        return dp[m][n] = 1 + lcs(a, b, m-1, n-1, dp);

    return dp[m][n] = max(
        lcs(a, b, m-1, n, dp),
        lcs(a, b, m, n-1, dp)
    );
}
```

### Problems

| #  | Problem                                         | Difficulty |
| -- | ----------------------------------------------- | ---------- |
| 1  | Longest Common Subsequence (LC 1143)            | 🟡 Medium  |
| 2  | Longest Common Substring                        | 🟡 Medium  |
| 3  | Printing LCS                                    | 🟡 Medium  |
| 4  | Shortest Common Supersequence (LC 1092)         | 🟡 Medium  |
| 5  | Minimum Insertions & Deletions                  | 🟡 Medium  |
| 6  | Longest Palindromic Subsequence (LC 516)        | 🟡 Medium  |
| 7  | Minimum Deletions to Make Palindrome            | 🟡 Medium  |
| 8  | Print Shortest Common Supersequence             | 🔴 Hard    |
| 9  | Longest Repeating Subsequence                   | 🟡 Medium  |
| 10 | Sequence Pattern Matching                       | 🟢 Easy    |
| 11 | Minimum Insertions to Make Palindrome (LC 1312) | 🔴 Hard    |

---

# Pattern 4 — Matrix Chain Multiplication (MCM)

### When to use

You are given a **single sequence** and must determine the optimal way to partition it.

### Key Insight

Try every partition point `k` between `i` and `j`.

```cpp
int solve(int i, int j, vector<vector<int>>& dp) {

    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;

    for (int k = i; k < j; k++) {

        int cost =
            solve(i, k, dp) +
            solve(k + 1, j, dp) +
            cost_of_combining;

        ans = min(ans, cost);
    }

    return dp[i][j] = ans;
}
```

### Problems

| # | Problem                          | Difficulty |
| - | -------------------------------- | ---------- |
| 1 | Matrix Chain Multiplication      | 🔴 Hard    |
| 2 | Palindrome Partitioning (LC 132) | 🔴 Hard    |
| 3 | Boolean Parenthesization         | 🔴 Hard    |
| 4 | Scrambled String (LC 87)         | 🔴 Hard    |
| 5 | Egg Dropping (LC 887)            | 🔴 Hard    |

---

# Pattern 5 — DP on Trees

### When to use

Problems on binary trees where each node's answer depends on its children.

### Key Insight

Perform a **post-order DFS**.

* Compute left subtree.
* Compute right subtree.
* Update a global answer.
* Return only the value required by the parent.

```cpp
int dfs(TreeNode* node, int& ans) {

    if (!node)
        return 0;

    int left = max(0, dfs(node->left, ans));
    int right = max(0, dfs(node->right, ans));

    ans = max(ans, left + right + node->val);

    return node->val + max(left, right);
}
```

### Problems

| # | Problem                                          | Difficulty |
| - | ------------------------------------------------ | ---------- |
| 1 | Diameter of Binary Tree (LC 543)                 | 🟢 Easy    |
| 2 | Maximum Path Sum (Any Node to Any Node) (LC 124) | 🔴 Hard    |
| 3 | Maximum Path Sum (Leaf to Leaf)                  | 🔴 Hard    |

---

# Problems by Difficulty

## 🟢 Easy (2)

| Problem                   | Pattern     |
| ------------------------- | ----------- |
| Sequence Pattern Matching | LCS         |
| Diameter of Binary Tree   | DP on Trees |

---

## 🟡 Medium (18)

| Problem                              | Pattern            |
| ------------------------------------ | ------------------ |
| 0/1 Knapsack                         | 0/1 Knapsack       |
| Subset Sum                           | 0/1 Knapsack       |
| Equal Sum Partition                  | 0/1 Knapsack       |
| Count of Subsets with Given Sum      | 0/1 Knapsack       |
| Count Subsets with Given Difference  | 0/1 Knapsack       |
| Target Sum                           | 0/1 Knapsack       |
| Unbounded Knapsack                   | Unbounded Knapsack |
| Rod Cutting                          | Unbounded Knapsack |
| Coin Change — Maximum Ways           | Unbounded Knapsack |
| Coin Change — Minimum Coins          | Unbounded Knapsack |
| Longest Common Subsequence           | LCS                |
| Longest Common Substring             | LCS                |
| Printing LCS                         | LCS                |
| Shortest Common Supersequence        | LCS                |
| Minimum Insertions & Deletions       | LCS                |
| Longest Palindromic Subsequence      | LCS                |
| Minimum Deletions to Make Palindrome | LCS                |
| Longest Repeating Subsequence        | LCS                |

---

## 🔴 Hard (10)

| Problem                                 | Pattern      |
| --------------------------------------- | ------------ |
| Minimum Subset Sum Difference           | 0/1 Knapsack |
| Print Shortest Common Supersequence     | LCS          |
| Minimum Insertions to Make Palindrome   | LCS          |
| Matrix Chain Multiplication             | MCM          |
| Palindrome Partitioning                 | MCM          |
| Boolean Parenthesization                | MCM          |
| Scrambled String                        | MCM          |
| Egg Dropping                            | MCM          |
| Maximum Path Sum (Any Node to Any Node) | DP on Trees  |
| Maximum Path Sum (Leaf to Leaf)         | DP on Trees  |

---

# Quick Decision Guide

```text
Does the problem involve selecting items with weight/capacity?

├── Use each item at most once?
│      → 0/1 Knapsack
│
└── Use each item unlimited times?
       → Unbounded Knapsack


Are two strings or sequences given?

├── Longest common part?
├── Shortest common supersequence?
├── String transformation?
└── Palindrome subsequence?
       → LCS Pattern


Do you need to split a sequence optimally?

├── Partition substrings?
├── Parenthesization?
└── Try every split point k?
       → Matrix Chain Multiplication


Is the input a tree?

└── Combine results from children?
       → DP on Trees
```

---

# Pattern Summary

| Pattern                     | Problems Solved | Key Technique           |
| --------------------------- | --------------: | ----------------------- |
| 0/1 Knapsack                |               7 | Take or leave each item |
| Unbounded Knapsack          |               4 | Reuse the same item     |
| Longest Common Subsequence  |              11 | Match or skip           |
| Matrix Chain Multiplication |               5 | Try every partition     |
| DP on Trees                 |               3 | Post-order DFS          |
| **Total**                   |          **30** |                         |
