# Sliding Window — Master Interview Preparation Sheet

> Consolidated from my original Sliding Window notes and the LeetCode pattern list.
> Target: fresher to 0–2 years experience, with selected advanced problems for stronger interview preparation.

## Problem count

- **62 problem entries** across the patterns and additional DSA section.
- **49 distinct problems** after accounting for problems repeated under multiple patterns or listed under equivalent names.
- The **Source** column identifies whether each problem came from the original Markdown notes, the LeetCode sheet, or both.
- Repeated entries are intentional where a problem teaches more than one technique.

## Pattern 1 — Fixed-Size Sliding Window

**Priority: 1 — Must Do**

**Core idea:** Maintain a window of exactly size `k`. Add the incoming element and remove the outgoing element.

| # | Problem | Source |
|---:|---|---|
| 1 | Maximum Sum Subarray of Size K | Original MD |
| 2 | Average of Subarrays of Size K | Original MD |
| 3 | First Negative Number in Every Window of Size K | Original MD |
| 4 | Maximum Average Subarray I | LeetCode |
| 5 | Maximum Sum of Distinct Subarrays With Length K | LeetCode |
| 6 | Contains Duplicate II | LeetCode |
| 7 | K Radius Subarray Averages | LeetCode |
| 8 | Maximum Points You Can Obtain from Cards | LeetCode |
| 9 | Maximum Vowels in a Substring of Given Length | LeetCode |

## Pattern 2 — Variable-Size Window: Longest Valid Window

**Priority: 1 — Must Do**

**Core idea:** Expand `right`, shrink `left` when the condition breaks, and track the maximum length.

| # | Problem | Source |
|---:|---|---|
| 1 | Longest Substring Without Repeating Characters | Original MD + LeetCode |
| 2 | Longest Subarray With Sum = K | Original MD |
| 3 | Longest Subarray of 1s After Deleting One Element | LeetCode |
| 4 | Maximum Erasure Value | LeetCode |
| 5 | Longest Semi-Repetitive Substring | LeetCode |

**Important:** The standard sum-based sliding window for `Longest Subarray With Sum = K` requires non-negative elements. For arbitrary integers, use Prefix Sum + HashMap.

## Pattern 3 — Variable-Size Window: Minimum Valid Window

**Priority: 1 — Must Do**

**Core idea:** Expand until the condition is satisfied, then shrink as much as possible while maintaining validity.

| # | Problem | Source |
|---:|---|---|
| 1 | Minimum Size Subarray Sum | Original MD + LeetCode |
| 2 | Minimum Window Substring | Original MD + LeetCode |
| 3 | Shortest Subarray to Be Removed to Make Array Sorted | LeetCode |

### Advanced extension

| # | Problem | Technique | Source |
|---:|---|---|---|
| 4 | Shortest Subarray With Sum at Least K | Prefix Sum + Monotonic Deque | LeetCode |

**Important:** `Shortest Subarray With Sum at Least K` is not a normal variable-size sliding-window problem when negative numbers are allowed.

## Pattern 4 — Frequency Map / Character Count Window

**Priority: 1 — Must Do**

**Core idea:** Maintain character or element frequencies using a HashMap or frequency array.

| # | Problem | Source |
|---:|---|---|
| 1 | Longest Substring With At Most K Distinct Characters | Original MD + LeetCode |
| 2 | Fruits Into Baskets | Original MD + LeetCode |
| 3 | Permutation in String | Original MD + LeetCode |
| 4 | Find All Anagrams in a String | Original MD + LeetCode |
| 5 | Longest Repeating Character Replacement | Original MD + LeetCode |
| 6 | Longest Substring With At Most Two Distinct Characters | LeetCode |
| 7 | Substring With Concatenation of All Words | LeetCode |
| 8 | Count Complete Substrings | LeetCode |
| 9 | Longest Substring With Equal Character Frequency | LeetCode |

**Note:** The last two require specialized frequency constraints; they are not just applications of the simplest frequency-map template.

## Pattern 5 — At Most K / Exactly K Subarrays

**Priority: 2 — Must Do**

**Core idea:**

```text
Exactly(K) = AtMost(K) - AtMost(K - 1)
```

| # | Problem | Source |
|---:|---|---|
| 1 | Count Subarrays With Exactly K Odd Numbers | Original MD |
| 2 | Subarrays With K Different Integers | LeetCode |
| 3 | Binary Subarrays With Sum | LeetCode |
| 4 | Number of Substrings Containing All Three Characters | LeetCode |
| 5 | Subarray Product Less Than K | Original MD + LeetCode |

**Important:** `Subarray Product Less Than K` uses an at-most-style counting window, but not the Exactly K subtraction formula.

## Pattern 6 — Flip / Replace at Most K Elements

**Priority: 2 — Important**

**Core idea:** Track the number of invalid elements and keep their count at most `k`.

| # | Problem | Source |
|---:|---|---|
| 1 | Max Consecutive Ones III | Original MD + LeetCode |
| 2 | Longest Subarray With At Most K Replacements | Original MD |

**Related problem:** `Longest Repeating Character Replacement` is listed under Pattern 4 because it combines a frequency map with a replacement constraint.

## Pattern 7 — Sum / Product Constraint Windows

**Priority: 2 — Important**

**Core idea:** Maintain a running sum or product and shrink the window when the constraint is violated.

| # | Problem | Source |
|---:|---|---|
| 1 | Longest Subarray With Sum = K | Original MD |
| 2 | Minimum Size Subarray Sum | Original MD + LeetCode |
| 3 | Subarray Product Less Than K | Original MD + LeetCode |
| 4 | Maximum Sum of Distinct Subarrays With Length K | LeetCode |
| 5 | Maximum Points You Can Obtain from Cards | LeetCode |

**Note:** Some problems also appear in other patterns. These repeated entries are cross-references, not additional unique questions.

## Pattern 8 — Prefix Sum + HashMap / Sliding Window

**Priority: 2 — Important**

**Core idea:** Use prefix sums to handle subarray-sum conditions where ordinary window shrinking is not reliable.

| # | Problem | Source |
|---:|---|---|
| 1 | Longest Subarray With Sum = K (general integers) | Original MD |
| 2 | Subarray Sum Equals K | LeetCode |
| 3 | Continuous Subarray Sum | LeetCode |
| 4 | Minimum Operations to Reduce X to Zero | LeetCode |
| 5 | Find Pivot Index | LeetCode |

**Technique notes:**
- `Subarray Sum Equals K` → Prefix Sum + HashMap.
- `Continuous Subarray Sum` → Prefix Sum + Remainder HashMap.
- `Minimum Operations to Reduce X to Zero` → Transform into a longest-subarray-sum problem.
- `Find Pivot Index` → Prefix Sum; it is not really a sliding-window problem.

## Pattern 9 — Monotonic Deque: Sliding Window Maximum / Minimum

**Priority: 3 — Important**

**Core idea:** Maintain a monotonic deque to efficiently track maximum and minimum values.

| # | Problem | Source |
|---:|---|---|
| 1 | Sliding Window Maximum | Original MD |
| 2 | Sliding Window Minimum | Original MD |
| 3 | Longest Subarray Where Max − Min ≤ K | Original MD |
| 4 | Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit | LeetCode |
| 5 | Shortest Subarray With Sum at Least K | LeetCode |
| 6 | Sliding Window Median | LeetCode |
| 7 | Constrained Subsequence Sum | LeetCode |
| 8 | Sum of Subarray Minimums | LeetCode |

**Important distinctions:**
- `Longest Subarray Where Max − Min ≤ K` and `Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit` refer to the same underlying LeetCode problem.
- `Shortest Subarray With Sum at Least K` uses Prefix Sum + Monotonic Deque.
- `Sliding Window Median` uses two heaps or an ordered data structure.
- `Constrained Subsequence Sum` combines a monotonic deque with Dynamic Programming.
- `Sum of Subarray Minimums` is primarily a Monotonic Stack problem.

## Pattern 10 — Dual Windows / Advanced Two Pointers

**Priority: 3 — Advanced**

**Core idea:** Maintain two related windows or combine sliding window with specialized state tracking.

| # | Problem | Source |
|---:|---|---|
| 1 | Longest Nice Subarray | LeetCode |
| 2 | Substring With Concatenation of All Words | LeetCode |
| 3 | Number of Substrings Containing All Three Characters | LeetCode |
| 4 | Subarrays With K Different Integers | LeetCode |
| 5 | Count Complete Substrings | LeetCode |

**Note:** Some problems are cross-listed because they combine frequency maps, multiple windows, or two pointers. `Longest Nice Subarray` is particularly useful for learning bitmask-based window state.

## Additional DSA Problems Worth Knowing

These appeared in the LeetCode list but do not fit cleanly into the 10 core patterns.

| # | Problem | Primary DSA topic | Source |
|---:|---|---|---|
| 1 | K Divisible Elements Subarrays | Hashing + Enumeration | LeetCode |
| 2 | Maximum Subarray Sum With One Deletion | Dynamic Programming | LeetCode |
| 3 | Prefix and Suffix Search | Trie + String Processing | LeetCode |
| 4 | Daily Temperatures | Monotonic Stack | LeetCode |
| 5 | Sum of Subarray Minimums | Monotonic Stack | LeetCode |

## Recommended Learning Order

1. Patterns 1–4: Fixed window, longest window, minimum window, frequency map.
2. Patterns 5–8: Exactly K, replacements, sum/product constraints, prefix sums.
3. Patterns 9–10: Monotonic deque, dual windows, advanced two pointers.
4. Finish with the additional DSA problems where relevant.

## Interview Reminders

- Sliding Window is not suitable for every subarray problem.
- Standard sum-based expand/shrink windows generally rely on non-negative (or positive, depending on the problem) array elements.
- For arbitrary integers, consider Prefix Sum + HashMap or Prefix Sum + Monotonic Deque.
- Learn why a window is valid and when it becomes invalid; do not just memorize templates.
- A problem may belong to more than one pattern. Count it once when tracking unique problems.
