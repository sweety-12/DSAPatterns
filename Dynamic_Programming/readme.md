# Dynamic Programming

## What is Dynamic Programming?

Dynamic Programming (DP) is an optimization technique that solves complex problems by breaking them into **overlapping subproblems**, solving each subproblem only once, and storing the result to avoid recomputation.

**Core idea:** If a problem has **optimal substructure** (optimal solution built from optimal sub-solutions) and **overlapping subproblems** (same subproblem solved multiple times), DP applies. Identify the recurrence, then either memoize top-down or build bottom-up.

```
Time Complexity:  O(n²) or O(n³) depending on problem
Space Complexity: O(n) or O(n²) for the DP table
```

> **Progress: 30 problems solved** across 5 patterns

---

## How to Identify a DP Problem

```
Does the problem ask for:
├── Count the number of ways?         → DP (usually)
├── Minimum / Maximum of something?   → DP (usually)
├── Is it possible / true / false?    → DP (usually)
└── Find the longest / shortest?      → DP (usually)

AND does it have:
├── Overlapping subproblems?          → Memoization will help
└── Optimal substructure?             → DP is applicable
```

> **Rule of thumb:** If brute force is exponential and you're recomputing the same states, DP is the tool.

---

## The Three Steps to Solve Any DP Problem

```
Step 1 — Recursive (Brute Force)
         Write the plain recursion. Don't optimize yet.
         Identify base cases and the recurrence relation.
         ↓
Step 2 — Memoization (Top-Down)
         Add a dp[][] table. Before computing, check if already solved.
         Store result before returning.
         ↓
Step 3 — Tabulation (Bottom-Up)
         Convert recursion to iteration.
         Fill the table from base cases upward.
         Optionally optimize space.
```

---

## Common Off-by-One Pitfalls

| Mistake | Fix |
|---|---|
| Wrong base case | Dry run with n=0 and n=1 explicitly |
| Forgetting to initialize dp table with -1 | Use `memset(dp, -1, sizeof(dp))` before memoization |
| Index mismatch between string and dp table | Shift string index by +1 when dp is 1-indexed |
| Mixing i=0 (item) with i=0 (capacity) | Keep separate loops clear — items outer, capacity inner |
| Printing DP solution without backtracking | Always trace back through the table, not recompute |

---

## Patterns & Solved Problems

---

### Pattern 1 — 0/1 Knapsack

**When to use:** You have N items each with a weight and value. A capacity W is given. Each item can be picked **at most once**. Find optimal selection.

**Key insight:** At every item, you have exactly two choices — **take it** or **leave it**. If you take it, capacity reduces. If you leave it, move to next item at same capacity. This binary choice is the hallmark of 0/1 Knapsack. All 7 problems below are disguised versions of this same recurrence.

```cpp
// 0/1 Knapsack — Top Down DP
int knapsack(int W, vector<int>& wt, vector<int>& val, int n, vector<vector<int>>& dp) {
    if (n == 0 || W == 0) return 0;
    if (dp[n][W] != -1) return dp[n][W];

    if (wt[n-1] <= W)
        return dp[n][W] = max(
            val[n-1] + knapsack(W - wt[n-1], wt, val, n-1, dp),  // take
            knapsack(W, wt, val, n-1, dp)                          // leave
        );
    else
        return dp[n][W] = knapsack(W, wt, val, n-1, dp);          // can't take
}
```

| # | Problem | Difficulty | File |
|---|---|---|---|
| 1 | 0/1 Knapsack (Recursive → Memoization → Top Down) | 🟡 Medium | [`01Knapsack.java`](./01Knapsack.java) |
| 2 | Subset Sum Problem | 🟡 Medium | [`SubsetSum.java`](./SubsetSum.java) |
| 3 | Equal Sum Partition Problem | 🟡 Medium | [`EqualSumPartition.java`](./EqualSumPartition.java) |
| 4 | Count of Subsets with Given Sum | 🟡 Medium | [`CountOfSubsetsWithGivenSum.java`](./CountOfSubsetsWithGivenSum.java) |
| 5 | Minimum Subset Sum Difference | 🔴 Hard | [`MinimumSubsetSumDifference.java`](./MinimumSubsetSumDifference.java) |
| 6 | Count Subsets with Given Difference | 🟡 Medium | [`CountSubsetsWithGivenDifference.java`](./CountSubsetsWithGivenDifference.java) |
| 7 | Target Sum — LC 494 | 🟡 Medium | [`TargetSum.java`](./TargetSum.java) |

---

### Pattern 2 — Unbounded Knapsack

**When to use:** Same setup as 0/1 Knapsack but each item can be picked **unlimited times**. The capacity shrinks but the item index does not move forward on a pick.

**Key insight:** The only change from 0/1 Knapsack — when you **take** an item, stay at the same index `n` instead of moving to `n-1`. This single line difference unlocks infinite reuse of each item.

```cpp
// Unbounded Knapsack — key difference from 0/1
if (wt[n-1] <= W)
    return dp[n][W] = max(
        val[n-1] + knapsack(W - wt[n-1], wt, val, n, dp),   // take — stay at n (not n-1)
        knapsack(W, wt, val, n-1, dp)                         // leave
    );
```

| # | Problem | Difficulty | File |
|---|---|---|---|
| 1 | Unbounded Knapsack | 🟡 Medium | [`UnboundedKnapsack.java`](./UnboundedKnapsack.java) |
| 2 | Rod Cutting Problem | 🟡 Medium | [`RodCutting.java`](./RodCutting.java) |
| 3 | Coin Change — Maximum Number of Ways | 🟡 Medium | [`CoinChangeMaxWays.java`](./CoinChangeMaxWays.java) |
| 4 | Coin Change — Minimum Number of Coins — LC 322 | 🟡 Medium | [`CoinChangeMinCoins.java`](./CoinChangeMinCoins.java) |

---

### Pattern 3 — Longest Common Subsequence (LCS)

**When to use:** Two strings are given. Problem involves finding commonality, similarity, or transformation cost between them. Subsequences, substrings, palindromes, and edit distances all reduce to LCS variants.

**Key insight:** Compare characters at `i` and `j`. If they match, both pointers move inward and you gain 1. If they don't match, try skipping from either string and take the best. This 2D recurrence is the foundation of 11 problems below.

```cpp
// LCS — Top Down DP
int lcs(string& a, string& b, int m, int n, vector<vector<int>>& dp) {
    if (m == 0 || n == 0) return 0;
    if (dp[m][n] != -1) return dp[m][n];

    if (a[m-1] == b[n-1])
        return dp[m][n] = 1 + lcs(a, b, m-1, n-1, dp);       // match
    else
        return dp[m][n] = max(
            lcs(a, b, m-1, n, dp),                             // skip from a
            lcs(a, b, m, n-1, dp)                              // skip from b
        );
}
```

| # | Problem | Difficulty | File |
|---|---|---|---|
| 1 | Longest Common Subsequence (Recursive → Memoization → Top Down) — LC 1143 | 🟡 Medium | [`LongestCommonSubsequence.java`](./LongestCommonSubsequence.java) |
| 2 | Longest Common Substring | 🟡 Medium | [`LongestCommonSubstring.java`](./LongestCommonSubstring.java) |
| 3 | Printing LCS | 🟡 Medium | [`PrintingLCS.java`](./PrintingLCS.java) |
| 4 | Shortest Common Supersequence — LC 1092 | 🟡 Medium | [`ShortestCommonSupersequence.java`](./ShortestCommonSupersequence.java) |
| 5 | Minimum Insertions & Deletions to Convert String A to B | 🟡 Medium | [`MinInsertionsAndDeletions.java`](./MinInsertionsAndDeletions.java) |
| 6 | Longest Palindromic Subsequence — LC 516 | 🟡 Medium | [`LongestPalindromicSubsequence.java`](./LongestPalindromicSubsequence.java) |
| 7 | Minimum Deletions to Make String Palindrome | 🟡 Medium | [`MinDeletionsToPalindrome.java`](./MinDeletionsToPalindrome.java) |
| 8 | Print Shortest Common Supersequence | 🟡 Medium | [`PrintShortestCommonSupersequence.java`](./PrintShortestCommonSupersequence.java) |
| 9 | Longest Repeating Subsequence | 🟡 Medium | [`LongestRepeatingSubsequence.java`](./LongestRepeatingSubsequence.java) |
| 10 | Sequence Pattern Matching | 🟢 Easy | [`SequencePatternMatching.java`](./SequencePatternMatching.java) |
| 11 | Minimum Insertions to Make String Palindrome — LC 1312 | 🔴 Hard | [`MinInsertionsToPalindrome.java`](./MinInsertionsToPalindrome.java) |

---

### Pattern 4 — Matrix Chain Multiplication (MCM)

**When to use:** You are given a **single sequence** and asked to split it optimally. The cost of splitting depends on both parts. Problems involving partitioning, parenthesization, or interval DP follow this pattern.

**Key insight:** Unlike Knapsack (left to right) or LCS (two strings), MCM splits the problem by placing a **partition point `k`** somewhere between `i` and `j`. Try every possible `k` and take the best. This i–k–j loop is the signature of MCM-style DP.

```cpp
// MCM General Format
int solve(int i, int j, ..., vector<vector<int>>& dp) {
    if (i >= j) return base_case;      // single element, no split possible
    if (dp[i][j] != -1) return dp[i][j];

    int ans = INT_MAX;                  // or INT_MIN depending on problem
    for (int k = i; k < j; k++) {      // try every partition point
        int cost = solve(i, k, ...) + solve(k+1, j, ...) + cost_of_combining;
        ans = min(ans, cost);           // or max
    }
    return dp[i][j] = ans;
}
```

| # | Problem | Difficulty | File |
|---|---|---|---|
| 1 | Matrix Chain Multiplication (Recursive → Memoization) | 🔴 Hard | [`MatrixChainMultiplication.java`](./MatrixChainMultiplication.java) |
| 2 | Palindrome Partitioning (Recursive → Memoization → Optimized) — LC 132 | 🔴 Hard | [`PalindromePartitioning.java`](./PalindromePartitioning.java) |
| 3 | Evaluate Expression to True / Boolean Parenthesization (Recursive → Memoized) | 🔴 Hard | [`BooleanParenthesization.java`](./BooleanParenthesization.java) |
| 4 | Scrambled String (Recursive → Memoized) — LC 87 | 🔴 Hard | [`ScrambledString.java`](./ScrambledString.java) |
| 5 | Egg Dropping Problem (Recursive → Memoization → Optimized) — LC 887 | 🔴 Hard | [`EggDropping.java`](./EggDropping.java) |

---

### Pattern 5 — DP on Trees

**When to use:** The problem is on a **binary tree or general tree** and requires aggregating results from children to compute the answer at each node. Diameter, path sum, and subtree queries all follow this pattern.

**Key insight:** Run a DFS. At each node, collect answers from left and right subtrees first (post-order). Combine them to compute the global answer, and return only the relevant value upward (usually the single best path — not both sides). The global answer and the return value are often **different**.

```cpp
// DP on Trees — post-order DFS template
int dfs(TreeNode* node, int& globalAns) {
    if (!node) return 0;

    int left  = max(0, dfs(node->left,  globalAns));   // gain from left
    int right = max(0, dfs(node->right, globalAns));   // gain from right

    globalAns = max(globalAns, left + right + node->val);  // update global

    return node->val + max(left, right);   // return single best path upward
}
```

| # | Problem | Difficulty | File |
|---|---|---|---|
| 1 | Diameter of a Binary Tree — LC 543 | 🟢 Easy | [`DiameterOfBinaryTree.java`](./DiameterOfBinaryTree.java) |
| 2 | Maximum Path Sum — Any Node to Any Node — LC 124 | 🔴 Hard | [`MaxPathSumAnyToAny.java`](./MaxPathSumAnyToAny.java) |
| 3 | Maximum Path Sum — Leaf to Leaf | 🔴 Hard | [`MaxPathSumLeafToLeaf.java`](./MaxPathSumLeafToLeaf.java) |

---

## Problems by Difficulty

### 🟢 Easy (2)
| Problem | Pattern | File |
|---|---|---|
| Sequence Pattern Matching | LCS | [`SequencePatternMatching.java`](./SequencePatternMatching.java) |
| Diameter of a Binary Tree | DP on Trees | [`DiameterOfBinaryTree.java`](./DiameterOfBinaryTree.java) |

### 🟡 Medium (18)
| Problem | Pattern | File |
|---|---|---|
| 0/1 Knapsack | 0/1 Knapsack | [`01Knapsack.java`](./01Knapsack.java) |
| Subset Sum Problem | 0/1 Knapsack | [`SubsetSum.java`](./SubsetSum.java) |
| Equal Sum Partition Problem | 0/1 Knapsack | [`EqualSumPartition.java`](./EqualSumPartition.java) |
| Count of Subsets with Given Sum | 0/1 Knapsack | [`CountOfSubsetsWithGivenSum.java`](./CountOfSubsetsWithGivenSum.java) |
| Count Subsets with Given Difference | 0/1 Knapsack | [`CountSubsetsWithGivenDifference.java`](./CountSubsetsWithGivenDifference.java) |
| Target Sum | 0/1 Knapsack | [`TargetSum.java`](./TargetSum.java) |
| Unbounded Knapsack | Unbounded Knapsack | [`UnboundedKnapsack.java`](./UnboundedKnapsack.java) |
| Rod Cutting Problem | Unbounded Knapsack | [`RodCutting.java`](./RodCutting.java) |
| Coin Change — Max Ways | Unbounded Knapsack | [`CoinChangeMaxWays.java`](./CoinChangeMaxWays.java) |
| Coin Change — Min Coins | Unbounded Knapsack | [`CoinChangeMinCoins.java`](./CoinChangeMinCoins.java) |
| Longest Common Subsequence | LCS | [`LongestCommonSubsequence.java`](./LongestCommonSubsequence.java) |
| Longest Common Substring | LCS | [`LongestCommonSubstring.java`](./LongestCommonSubstring.java) |
| Printing LCS | LCS | [`PrintingLCS.java`](./PrintingLCS.java) |
| Shortest Common Supersequence | LCS | [`ShortestCommonSupersequence.java`](./ShortestCommonSupersequence.java) |
| Minimum Insertions & Deletions | LCS | [`MinInsertionsAndDeletions.java`](./MinInsertionsAndDeletions.java) |
| Longest Palindromic Subsequence | LCS | [`LongestPalindromicSubsequence.java`](./LongestPalindromicSubsequence.java) |
| Minimum Deletions to Make Palindrome | LCS | [`MinDeletionsToPalindrome.java`](./MinDeletionsToPalindrome.java) |
| Longest Repeating Subsequence | LCS | [`LongestRepeatingSubsequence.java`](./LongestRepeatingSubsequence.java) |

### 🔴 Hard (10)
| Problem | Pattern | File |
|---|---|---|
| Minimum Subset Sum Difference | 0/1 Knapsack | [`MinimumSubsetSumDifference.java`](./MinimumSubsetSumDifference.java) |
| Print Shortest Common Supersequence | LCS | [`PrintShortestCommonSupersequence.java`](./PrintShortestCommonSupersequence.java) |
| Minimum Insertions to Make Palindrome | LCS | [`MinInsertionsToPalindrome.java`](./MinInsertionsToPalindrome.java) |
| Matrix Chain Multiplication | MCM | [`MatrixChainMultiplication.java`](./MatrixChainMultiplication.java) |
| Palindrome Partitioning | MCM | [`PalindromePartitioning.java`](./PalindromePartitioning.java) |
| Boolean Parenthesization | MCM | [`BooleanParenthesization.java`](./BooleanParenthesization.java) |
| Scrambled String | MCM | [`ScrambledString.java`](./ScrambledString.java) |
| Egg Dropping Problem | MCM | [`EggDropping.java`](./EggDropping.java) |
| Maximum Path Sum — Any to Any | DP on Trees | [`MaxPathSumAnyToAny.java`](./MaxPathSumAnyToAny.java) |
| Maximum Path Sum — Leaf to Leaf | DP on Trees | [`MaxPathSumLeafToLeaf.java`](./MaxPathSumLeafToLeaf.java) |

---

## Quick Decision Guide

```
Does the problem ask you to pick items with a weight/capacity constraint?
├── Each item used at most once?         → 0/1 Knapsack (Pattern 1)
└── Each item used unlimited times?      → Unbounded Knapsack (Pattern 2)

Are two strings / sequences given?
├── Find longest common part?            → LCS (Pattern 3)
├── Find shortest common supersequence?  → LCS (Pattern 3)
├── Convert one string to another?       → LCS (Pattern 3)
└── Palindrome subsequence / insertions? → LCS (Pattern 3) — run LCS(s, reverse(s))

Is a single sequence given and you need to split it optimally?
├── Partition into substrings?           → MCM (Pattern 4)
├── Parenthesization cost?               → MCM (Pattern 4)
└── Try every split point k in [i, j]   → MCM (Pattern 4)

Is the input a Binary Tree?
└── Aggregate from children upward?      → DP on Trees (Pattern 5)
    ├── Return single best path up
    └── Update global answer at each node
```

---

## Pattern Summary

| Pattern | Problems Solved | Key Technique |
|---|---|---|
| 1. 0/1 Knapsack | 7 | Take or leave each item once |
| 2. Unbounded Knapsack | 4 | Take item, stay at same index |
| 3. LCS | 11 | Match or skip from two sequences |
| 4. MCM | 5 | Try every partition point k in \[i, j\] |
| 5. DP on Trees | 3 | Post-order DFS, return vs global answer |
| **Total** | **30** | |

---
