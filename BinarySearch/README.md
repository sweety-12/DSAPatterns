# Binary Search

## What is Binary Search?

Binary Search is a searching algorithm that finds the position of a target value within a **sorted** (or monotonically structured) dataset. Instead of scanning every element linearly, it repeatedly halves the search space by comparing the target to the middle element.

**Core idea:** If the middle element is too big, discard the right half. If it's too small, discard the left half. Repeat until found or the space is exhausted.

```
Time Complexity:  O(log n)
Space Complexity: O(1) — iterative | O(log n) — recursive call stack
```

> **Progress: 28 problems solved** across 6 patterns

---

## The Two Templates

### Template 1 — `lo <= hi` (exact match search)

Use when you're looking for a specific value and want to return `-1` if not found.

```cpp
int binarySearch(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;   // avoids integer overflow

        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
```

### Template 2 — `lo < hi` (boundary / answer space search)

Use when finding the **first/last position** that satisfies a condition, or binary searching on an answer range.

```cpp
int binarySearchBoundary(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size();   // hi = size, not size - 1

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;

        if (condition(mid))   // e.g. nums[mid] >= target
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;   // lo == hi at termination
}
```

> **Rule of thumb:** Exact hit → Template 1. Boundary / predicate / answer space → Template 2.

---

## Common Off-by-One Pitfalls

| Mistake | Fix |
|---|---|
| `mid = (lo + hi) / 2` can overflow | Use `lo + (hi - lo) / 2` |
| Mixing `hi = mid` with `lo <= hi` loop | Match pointer moves to your `while` condition |
| Infinite loop when lo and hi are adjacent | One pointer must always move each iteration |
| Wrong initial `hi` | `size - 1` for Template 1, `size` for Template 2 |

---

## Patterns & Solved Problems

---

### Pattern 1 — Fundamentals (Lower/Upper Bound & Classic Search)

**When to use:** Array is sorted. Finding exact values, boundaries, insertion positions, floor/ceil.

**Key insight:** `lower_bound` = first index where `arr[i] >= target`. `upper_bound` = first index where `arr[i] > target`. Everything else builds on these two.

```cpp
// Lower Bound — first position where arr[i] >= target
int lowerBound(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] >= target) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}
```

| # | Problem | Difficulty | File |
|---|---|---|---|
| 1 | Lower Bound & Upper Bound | 🟢 Easy | [`LowerBound_And_UpperBound.cpp`](./LowerBound_And_UpperBound.cpp) |
| 2 | Floor and Ceil in Sorted Array | 🟢 Easy | [`floor_and_ceil.cpp`](./floor_and_ceil.cpp) |
| 3 | Search Insert Position — LC 35 | 🟢 Easy | [`SearchInsertPosition.cpp`](./SearchInsertPosition.cpp) |
| 4 | First and Last Occurrence — LC 34 | 🟡 Medium | [`firstAndLastOccurrence.cpp`](./firstAndLastOccurrence.cpp) |
| 5 | Single Element in Sorted Array — LC 540 | 🟡 Medium | [`SingleElementInSortedArray.cpp`](./SingleElementInSortedArray.cpp) |

---

### Pattern 2 — Binary Search on Rotated Sorted Array

**When to use:** Array was sorted but rotated at an unknown pivot.

**Key insight:** One half is **always** sorted. Compare `nums[lo]` with `nums[mid]` to identify which half, then check if target falls in it.

```cpp
// One half is always sorted — use that to decide direction
if (nums[lo] <= nums[mid]) {          // left half is sorted
    if (nums[lo] <= target && target < nums[mid])
        hi = mid - 1;
    else
        lo = mid + 1;
} else {                               // right half is sorted
    if (nums[mid] < target && target <= nums[hi])
        lo = mid + 1;
    else
        hi = mid - 1;
}
```

| # | Problem | Difficulty | File |
|---|---|---|---|
| 1 | Search in Rotated Sorted Array — LC 33 | 🟡 Medium | [`SearchInRotatedSortedArray.cpp`](./SearchInRotatedSortedArray.cpp) |
| 2 | Search in Rotated Sorted Array II — LC 81 | 🟡 Medium | [`SearchInRotatedArrayII.cpp`](./SearchInRotatedArrayII.cpp) |
| 3 | Find Minimum in Rotated Sorted Array — LC 153 | 🟡 Medium | [`findMinimumInRotatedSortedArray.cpp`](./findMinimumInRotatedSortedArray.cpp) |
| 4 | Find Number of Times Array is Rotated | 🟡 Medium | [`FindNoOfTimesArrayIsRotated.cpp`](./FindNoOfTimesArrayIsRotated.cpp) |

---

### Pattern 3 — Peak Finding

**When to use:** No sorted guarantee — need a local maximum. Works in both 1D arrays and 2D grids.

**Key insight:** Moving toward the **larger neighbor** always leads to a peak. If `nums[mid] < nums[mid+1]`, a peak exists to the right — otherwise to the left (or at mid).

| # | Problem | Difficulty | File |
|---|---|---|---|
| 1 | Find Peak Element — LC 162 | 🟡 Medium | [`FindPeakElement.cpp`](./FindPeakElement.cpp) |
| 2 | Find Peak Element II — LC 1901 | 🔴 Hard | [`FindPeakElementII.cpp`](./FindPeakElementII.cpp) |

---

### Pattern 4 — Binary Search on 2D Matrix

**When to use:** Searching or aggregating across rows/columns with sorted guarantees.

**Key insight:**
- If row `i` max < row `i+1` min → flatten to 1D and standard binary search: `row = mid / cols`, `col = mid % cols`
- If only rows and columns are individually sorted → staircase search from top-right corner: O(m + n)
- For finding row with max ones → use lower bound on each row

| # | Problem | Difficulty | File |
|---|---|---|---|
| 1 | Row With Maximum Ones | 🟢 Easy | [`RowWithMaximumOnes.cpp`](./RowWithMaximumOnes.cpp) |
| 2 | Search a 2D Matrix — LC 74 | 🟡 Medium | [`SearchInA2DMatrix.cpp`](./SearchInA2DMatrix.cpp) |
| 3 | Search a 2D Matrix II — LC 240 | 🟡 Medium | [`SearchIna2DMatrix2.cpp`](./SearchIna2DMatrix2.cpp) |
| 4 | Median in a Row Wise Sorted Matrix | 🔴 Hard | [`MedianInARowWiseSortedMatrix.cpp`](./MedianInARowWiseSortedMatrix.cpp) |

---

### Pattern 5 — Binary Search on Answer Space (MOST IMPORTANT PATTERN FOR FAANG/MNC's)

**When to use:** The array itself may not be sorted, but the *answer* lies in a monotonic value range. Binary search on possible answer values, not indices.

**Key insight:** Define a `feasible(mid)` function. If it's monotonic — works for large values, fails for small (or vice versa) — binary search finds the exact tipping point.

```cpp
// General answer space template
int lo = min_possible_answer, hi = max_possible_answer;

while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (feasible(mid))
        hi = mid;       // mid could be the answer, don't discard it
    else
        lo = mid + 1;
}
return lo;
```

> ⚠️ **Most important pattern for FAANG.** Problems won't look like binary search — you have to spot the monotonic property yourself.

| # | Problem | Difficulty | File |
|---|---|---|---|
| 1 | Sqrt of a Number — LC 69 | 🟢 Easy | [`sqrtOfNumber.cpp`](./sqrtOfNumber.cpp) |
| 2 | Find Nth Root of a Number | 🟡 Medium | [`FindNthRootofANumber.cpp`](./FindNthRootofANumber.cpp) |
| 3 | Koko Eating Bananas — LC 875 | 🟡 Medium | [`KokoEatingBananas.cpp`](./KokoEatingBananas.cpp) |
| 4 | Find the Smallest Divisor — LC 1283 | 🟡 Medium | [`findTheSmallestDivisor.cpp`](./findTheSmallestDivisor.cpp) |
| 5 | Minimum No. of Days to Make a Bouquet — LC 1482 | 🟡 Medium | [`MinuminNoOfDaysToMakeABouquet.cpp`](./MinuminNoOfDaysToMakeABouquet.cpp) |
| 6 | Capacity to Ship Packages Within D Days — LC 1011 | 🟡 Medium | [`CapacityToShipPackagesWithinDdays.cpp`](./CapacityToShipPackagesWithinDdays.cpp) |
| 7 | Book Allocation Problem | 🟡 Medium | [`bookAllocation.cpp`](./bookAllocation.cpp) |
| 8 | Aggressive Cows | 🟡 Medium | [`AggressiveCows.cpp`](./AggressiveCows.cpp) |
| 9 | Split Array Largest Sum — LC 410 | 🔴 Hard | [`SplitArrayLargestSum.cpp`](./SplitArrayLargestSum.cpp) |
| 10 | Minimize Max Distance to Gas Stations — LC 774 | 🔴 Hard | [`minimizeMaxDistanceToGasStations.cpp`](./minimizeMaxDistanceToGasStations.cpp) |

---

### Pattern 6 — Kth Element / Median Across Sorted Structures

**When to use:** Finding the kth smallest/largest across two sorted arrays, or the median across a sorted matrix — where merging everything is too expensive.

**Key insight:** Binary search on the value range or on the partition. For two sorted arrays, binary search on a partition of the smaller array and balance both halves. For kth element, count how many elements are ≤ mid.

```cpp
// Kth element across two sorted arrays — binary search on partition
// Ensure nums1 is the smaller array
int lo = max(0, k - (int)nums2.size());
int hi = min(k, (int)nums1.size());

while (lo <= hi) {
    int cut1 = (lo + hi) / 2;
    int cut2 = k - cut1;
    // check max of left parts <= min of right parts
}
```

| # | Problem | Difficulty | File |
|---|---|---|---|
| 1 | Find Kth Positive Number — LC 1539 | 🟢 Easy | [`FindKthPositiveNumber.cpp`](./FindKthPositiveNumber.cpp) |
| 2 | Kth Element of Two Sorted Arrays | 🟡 Medium | [`kthElementOfTwoSortedArray.cpp`](./kthElementOfTwoSortedArray.cpp) |
| 3 | Median of Two Sorted Arrays — LC 4 | 🔴 Hard | [`MedianOf2SortedArray.cpp`](./MedianOf2SortedArray.cpp) |

---

## Problems by Difficulty

### 🟢 Easy (6)
| Problem | Pattern | File |
|---|---|---|
| Lower Bound & Upper Bound | Fundamentals | [`LowerBound_And_UpperBound.cpp`](./LowerBound_And_UpperBound.cpp) |
| Floor and Ceil | Fundamentals | [`floor_and_ceil.cpp`](./floor_and_ceil.cpp) |
| Search Insert Position | Fundamentals | [`SearchInsertPosition.cpp`](./SearchInsertPosition.cpp) |
| Row With Maximum Ones | 2D Matrix | [`RowWithMaximumOnes.cpp`](./RowWithMaximumOnes.cpp) |
| Sqrt of a Number | Answer Space | [`sqrtOfNumber.cpp`](./sqrtOfNumber.cpp) |
| Find Kth Positive Number | Kth Element | [`FindKthPositiveNumber.cpp`](./FindKthPositiveNumber.cpp) |

### 🟡 Medium (17)
| Problem | Pattern | File |
|---|---|---|
| First and Last Occurrence | Fundamentals | [`firstAndLastOccurrence.cpp`](./firstAndLastOccurrence.cpp) |
| Single Element in Sorted Array | Fundamentals | [`SingleElementInSortedArray.cpp`](./SingleElementInSortedArray.cpp) |
| Search in Rotated Sorted Array | Rotated Array | [`SearchInRotatedSortedArray.cpp`](./SearchInRotatedSortedArray.cpp) |
| Search in Rotated Sorted Array II | Rotated Array | [`SearchInRotatedArrayII.cpp`](./SearchInRotatedArrayII.cpp) |
| Find Minimum in Rotated Sorted Array | Rotated Array | [`findMinimumInRotatedSortedArray.cpp`](./findMinimumInRotatedSortedArray.cpp) |
| Find No. of Times Array is Rotated | Rotated Array | [`FindNoOfTimesArrayIsRotated.cpp`](./FindNoOfTimesArrayIsRotated.cpp) |
| Find Peak Element | Peak Finding | [`FindPeakElement.cpp`](./FindPeakElement.cpp) |
| Search a 2D Matrix | 2D Matrix | [`SearchInA2DMatrix.cpp`](./SearchInA2DMatrix.cpp) |
| Search a 2D Matrix II | 2D Matrix | [`SearchIna2DMatrix2.cpp`](./SearchIna2DMatrix2.cpp) |
| Find Nth Root of a Number | Answer Space | [`FindNthRootofANumber.cpp`](./FindNthRootofANumber.cpp) |
| Koko Eating Bananas | Answer Space | [`KokoEatingBananas.cpp`](./KokoEatingBananas.cpp) |
| Find the Smallest Divisor | Answer Space | [`findTheSmallestDivisor.cpp`](./findTheSmallestDivisor.cpp) |
| Min Days to Make a Bouquet | Answer Space | [`MinuminNoOfDaysToMakeABouquet.cpp`](./MinuminNoOfDaysToMakeABouquet.cpp) |
| Capacity to Ship Packages | Answer Space | [`CapacityToShipPackagesWithinDdays.cpp`](./CapacityToShipPackagesWithinDdays.cpp) |
| Book Allocation Problem | Answer Space | [`bookAllocation.cpp`](./bookAllocation.cpp) |
| Aggressive Cows | Answer Space | [`AggressiveCows.cpp`](./AggressiveCows.cpp) |
| Kth Element of Two Sorted Arrays | Kth Element | [`kthElementOfTwoSortedArray.cpp`](./kthElementOfTwoSortedArray.cpp) |

### 🔴 Hard (5)
| Problem | Pattern | File |
|---|---|---|
| Find Peak Element II | Peak Finding | [`FindPeakElementII.cpp`](./FindPeakElementII.cpp) |
| Median in Row Wise Sorted Matrix | 2D Matrix | [`MedianInARowWiseSortedMatrix.cpp`](./MedianInARowWiseSortedMatrix.cpp) |
| Split Array Largest Sum | Answer Space | [`SplitArrayLargestSum.cpp`](./SplitArrayLargestSum.cpp) |
| Minimize Max Distance to Gas Stations | Answer Space | [`minimizeMaxDistanceToGasStations.cpp`](./minimizeMaxDistanceToGasStations.cpp) |
| Median of Two Sorted Arrays | Kth Element | [`MedianOf2SortedArray.cpp`](./MedianOf2SortedArray.cpp) |

---

## Quick Decision Guide

```
Is the array sorted?
├── Yes, fully sorted
│   ├── Exact value search?         → Template 1 (lo <= hi)
│   ├── Boundary / floor / ceil?    → Template 2, lower/upper bound
│   └── Single element anomaly?     → SingleElementInSortedArray
│
├── Yes, but rotated?
│   ├── Find target?                → SearchInRotatedSortedArray
│   └── Find min / rotation count? → findMinimumInRotatedSortedArray
│
├── Need local maximum?             → Peak Finding (Pattern 3)
│
├── 2D Matrix?
│   ├── Row[i] max < Row[i+1] min?  → Flatten to 1D (LC 74)
│   ├── Rows & cols sorted?         → Staircase search (LC 240)
│   └── Find median?                → Binary search on value range
│
├── Answer in a value range?        → Answer Space (Pattern 5)
│   └── Ask: "can I feasibly achieve X?" → binary search on X
│
└── Kth element across sorted arrays?  → Partition binary search (Pattern 6)
```

---

## Pattern Summary

| Pattern | Problems Solved | Key Technique |
|---|---|---|
| 1. Fundamentals | 5 | Lower/Upper bound templates |
| 2. Rotated Array | 4 | Identify sorted half, decide direction |
| 3. Peak Finding | 2 | Move toward larger neighbor |
| 4. 2D Matrix | 4 | Flatten / staircase / value range |
| 5. Answer Space | 10 | `feasible(mid)` monotonic check |
| 6. Kth Element | 3 | Partition or count ≤ mid |
| **Total** | **28** | |
