# Binary Search

## What is Binary Search?

Binary Search is a searching algorithm that finds the position of a target value within a **sorted** (or monotonically structured) dataset. Instead of scanning every element linearly, it repeatedly halves the search space by comparing the target to the middle element.

**Core idea:** If the middle element is too big, discard the right half. If it's too small, discard the left half. Repeat until found or the space is exhausted.

```
Time Complexity:  O(log n)
Space Complexity: O(1) — iterative | O(log n) — recursive call stack
```

---

## The Two Templates

These two templates cover almost every binary search problem. Understand *when* to use each.

### Template 1 — `lo <= hi` (exact match search)

Use when you're looking for a specific value and want to return `-1` if not found.

```python
def binary_search(nums, target):
    lo, hi = 0, len(nums) - 1

    while lo <= hi:
        mid = lo + (hi - lo) // 2   # avoids integer overflow

        if nums[mid] == target:
            return mid
        elif nums[mid] < target:
            lo = mid + 1
        else:
            hi = mid - 1

    return -1
```

### Template 2 — `lo < hi` (boundary / leftmost search)

Use when you're finding the **first/last position** that satisfies a condition (predicate-based search).

```python
def binary_search_boundary(nums, target):
    lo, hi = 0, len(nums)   # hi = len(nums), not len - 1

    while lo < hi:
        mid = lo + (hi - lo) // 2

        if condition(mid):   # e.g., nums[mid] >= target
            hi = mid
        else:
            lo = mid + 1

    return lo   # lo == hi at termination
```

> **Rule of thumb:** If you need an exact hit → Template 1. If you need a boundary or the answer to a yes/no predicate → Template 2.

---

## Common Off-by-One Pitfalls

| Mistake | Fix |
|---|---|
| `mid = (lo + hi) // 2` can overflow in some languages | Use `lo + (hi - lo) // 2` |
| `hi = mid` vs `hi = mid - 1` — wrong template mix | Match your `while` condition to your pointer moves |
| Infinite loop when `lo` and `hi` are adjacent | Ensure one pointer always moves each iteration |
| Wrong initial `hi` value | `len - 1` for Template 1, `len` for Template 2 |

---

## Patterns

---

### Pattern 1 — Classic Binary Search on Sorted Array

**When to use:** Array is sorted. You want an exact value or its insertion position.

**Key insight:** Standard lo/hi/mid. Get this down cold — every other pattern extends it.

| # | Problem | Difficulty | Notes |
|---|---|---|---|
| 1 | [Binary Search](https://leetcode.com/problems/binary-search/) — LC 704 | 🟢 Easy | Textbook implementation |
| 2 | [Search Insert Position](https://leetcode.com/problems/search-insert-position/) — LC 35 | 🟢 Easy | First position ≥ target |
| 3 | [Find First and Last Position of Element](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) — LC 34 | 🟡 Medium | Two binary searches |
| 4 | Count of occurrences in sorted array | 🟡 Medium | `last - first + 1` |

---

### Pattern 2 — Binary Search on Rotated / Modified Sorted Array

**When to use:** Array was sorted but rotated at an unknown pivot. One half is always sorted — use that to decide where to search.

**Key insight:** Check which half is sorted by comparing `nums[lo]` with `nums[mid]`. Then check if the target falls in the sorted half.

```python
# Rotated array template
while lo <= hi:
    mid = lo + (hi - lo) // 2
    if nums[mid] == target:
        return mid
    if nums[lo] <= nums[mid]:          # left half is sorted
        if nums[lo] <= target < nums[mid]:
            hi = mid - 1
        else:
            lo = mid + 1
    else:                               # right half is sorted
        if nums[mid] < target <= nums[hi]:
            lo = mid + 1
        else:
            hi = mid - 1
```

| # | Problem | Difficulty | Notes |
|---|---|---|---|
| 1 | [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/) — LC 33 | 🟡 Medium | No duplicates |
| 2 | [Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/) — LC 81 | 🟡 Medium | With duplicates — worst case O(n) |
| 3 | [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) — LC 153 | 🟡 Medium | No duplicates |
| 4 | [Find Minimum in Rotated Sorted Array II](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/) — LC 154 | 🔴 Hard | With duplicates |

---

### Pattern 3 — Binary Search on Answer Space

**When to use:** The array itself may not be sorted, but the *answer* lies in a monotonic value range. You binary search on possible answer values, not indices.

**Key insight:** Define a `feasible(mid)` function. If the answer space is monotonic (feasible for large values, not for small — or vice versa), binary search finds the tipping point.

```python
# General template
lo, hi = min_possible_answer, max_possible_answer

while lo < hi:
    mid = lo + (hi - lo) // 2
    if feasible(mid):
        hi = mid          # mid could be the answer, don't discard it
    else:
        lo = mid + 1

return lo
```

> This is the most important pattern for FAANG. Problems don't look like binary search — you have to recognize the monotonic property yourself.

| # | Problem | Difficulty | Notes |
|---|---|---|---|
| 1 | [Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/) — LC 875 | 🟡 Medium | Classic intro to this pattern |
| 2 | [Capacity to Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/) — LC 1011 | 🟡 Medium | feasible = can ship in D days |
| 3 | [Minimum Number of Days to Make m Bouquets](https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/) — LC 1482 | 🟡 Medium | Binary search on days |
| 4 | [Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/) — LC 410 | 🔴 Hard | feasible = can split into ≤ k parts |
| 5 | [Minimize Max Distance to Gas Station](https://leetcode.com/problems/minimize-max-distance-to-gas-station/) — LC 774 | 🔴 Hard | Binary search on floating point |

---

### Pattern 4 — Finding a Peak / Local Extremum

**When to use:** Array has no full sorted guarantee, but you need a local maximum. Moving toward the larger neighbor always leads to a peak.

**Key insight:** If `nums[mid] < nums[mid+1]`, a peak exists to the right. Otherwise it exists to the left (or at mid). This gives a valid binary search even without global sorting.

| # | Problem | Difficulty | Notes |
|---|---|---|---|
| 1 | [Find Peak Element](https://leetcode.com/problems/find-peak-element/) — LC 162 | 🟡 Medium | 1D — O(log n) |
| 2 | [Find a Peak Element II](https://leetcode.com/problems/find-a-peak-grid/) — LC 1901 | 🔴 Hard | 2D matrix — O(m log n) |

---

### Pattern 5 — Binary Search on 2D Matrix

**When to use:** Matrix rows and columns are sorted. Treat it as a flattened 1D sorted array.

**Key insight:** For an `m x n` matrix, map `index → (index // n, index % n)`. This only works when row `i` max < row `i+1` min (LC 74). If that's not guaranteed, use the staircase approach instead (LC 240).

| # | Problem | Difficulty | Notes |
|---|---|---|---|
| 1 | [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/) — LC 74 | 🟡 Medium | Flatten to 1D binary search |
| 2 | [Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/) — LC 240 | 🟡 Medium | Staircase search — O(m + n) |

---

### Pattern 6 — Kth Smallest / Largest in Sorted Structure

**When to use:** You need the kth element across a sorted matrix, merged sorted lists, or a multiplication table — where extracting all values is expensive.

**Key insight:** Binary search on the value range `[lo, hi]`. For each `mid`, count how many elements are ≤ mid. Find the smallest value where `count >= k`.

```python
lo, hi = min_val, max_val

while lo < hi:
    mid = lo + (hi - lo) // 2
    if count_less_equal(mid) >= k:
        hi = mid
    else:
        lo = mid + 1

return lo
```

| # | Problem | Difficulty | Notes |
|---|---|---|---|
| 1 | [Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/) — LC 378 | 🟡 Medium | Count ≤ mid using staircase |
| 2 | [Kth Smallest Number in Multiplication Table](https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/) — LC 668 | 🔴 Hard | Count with division per row |
| 3 | [Find Kth Smallest Pair Distance](https://leetcode.com/problems/find-k-th-smallest-pair-distance/) — LC 719 | 🔴 Hard | Sort + sliding window for count |
| 4 | [Median of Two Sorted Arrays](https://leetcode.com/problems/median-of-two-sorted-arrays/) — LC 4 | 🔴 Hard | Binary search on partition |

---

### Pattern 7 — Binary Search with Custom Predicate

**When to use:** The comparison isn't a simple value check. You define a monotonic boolean predicate (false...false...true...true) and find the first `true`.

**Key insight:** Any problem where you can write `is_valid(x)` that transitions exactly once from `False` to `True` across the search space is a binary search problem.

| # | Problem | Difficulty | Notes |
|---|---|---|---|
| 1 | [H-Index II](https://leetcode.com/problems/h-index-ii/) — LC 275 | 🟡 Medium | Predicate: `nums[mid] >= n - mid` |
| 2 | [Magnetic Force Between Two Balls](https://leetcode.com/problems/magnetic-force-between-two-balls/) — LC 1552 | 🟡 Medium | Greedy feasibility check |
| 3 | [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) — LC 300 | 🟡 Medium | Patience sorting with BS |
| 4 | [Russian Doll Envelopes](https://leetcode.com/problems/russian-doll-envelopes/) — LC 354 | 🔴 Hard | 2D LIS — sort trick + BS |

---

## Suggested Practice Order

```
Week 1 → Pattern 1 (Classic) + Pattern 3 (Answer Space)
Week 2 → Pattern 2 (Rotated Array) + Pattern 4 (Peak)
Week 3 → Pattern 5 (2D Matrix) + Pattern 6 (Kth Smallest)
Week 4 → Pattern 7 (Custom Predicate) + Revision
```

> Start with Pattern 3 early — it's the most frequently tested at FAANG for 0–2 yrs exp and takes the most practice to recognize in the wild.

---

## Quick Decision Guide

```
Is the array sorted?
├── Yes → Classic BS (Pattern 1)
│   ├── Array rotated? → Pattern 2
│   └── Looking for boundary? → Template 2
│
├── No, but answer is in a value range?
│   └── Binary search on answer space (Pattern 3)
│
├── Need a local max/min?
│   └── Peak finding (Pattern 4)
│
├── 2D matrix?
│   └── Flatten if fully sorted (Pattern 5), else staircase
│
└── Need Kth element across sorted structures?
    └── Binary search on value + count (Pattern 6)
```
