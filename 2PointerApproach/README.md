# Two Pointer Approach

The **Two Pointer** technique uses two index variables that move through a data structure — typically an array or string — to solve problems in **O(n) time and O(1) space**. Instead of using nested loops (O(n²)), the two pointers eliminate redundant comparisons by making intelligent decisions about which pointer to move at each step. It is one of the most frequently tested patterns in MAANG interviews and appears across array, string, and linked list problems.

---

## Patterns

### Pattern 1 — Opposite Ends

```
L ————————————> <———————————— R
[1,  3,  5,  7,  9,  11,  13]
```

Place one pointer at the start and one at the end of a **sorted** array. Move them inward based on whether the current result is too large or too small relative to the target. Each comparison eliminates an entire subrange, giving O(n) time.

**Problems**

| # | Problem |
|---|---------|
| 1 | PairWithTargetSum |
| 2 | TripletSumToZero |
| 3 | TripletSumCloseToTarget |
| 4 | ThreeSumClosest |
| 5 | TripletWithSmallerSum |
| 6 | QuadrupleSumToTarget |
| 7 | ThreeSumWithMultiplicity |
| 8 | MaxNumberOfKSumPairs |
| 9 | SquaringASortedArray |
| 10 | ValidPalindrome |

---

### Pattern 2 — Slow and Fast Pointers

```
S ——> (1 step)
F ————————> (2 steps)
[A] -> [B] -> [C] -> [D] -> [E] -> [C] (cycle)
```

One pointer moves one step at a time, the other moves two. Used to detect cycles in linked lists, find the midpoint of a list, or detect patterns that repeat. When fast reaches the end, slow is at the midpoint. If fast and slow ever meet mid-traversal, a cycle exists.

**Problems**

| # | Problem |
|---|---------|
| 1 | FindTheCelebrity |
| 2 | NextGreaterElementIII |

---

### Pattern 3 — Partition (Dutch National Flag)

```
[  0s  |  unknowns  |  2s  ]
        ↑            ↑
       low/mid      high
```

One or two boundary pointers divide the array into regions in-place. The `mid` pointer scans forward and swaps elements into the correct region. No extra space needed. This is the foundation of QuickSort's partition step and in-place array reorganization problems.

**Problems**

| # | Problem |
|---|---------|
| 1 | SortColors / DutchFlag |
| 2 | FindAllDuplicatesInAnArray |
| 3 | FirstMissingPositive |
| 4 | ArrayOfDoubledPairs |
| 5 | ShortestWindowSort |
| 6 | ValidMountainArray |
| 7 | LongestMountainInArray |

---

### Pattern 4 — Merge Two Sorted Arrays

```
A: [1,  3,  8]
    i
B: [2,  5,  9]
    j
→ Merged: [1, 2, 3, 5, 8, 9]
```

One pointer per sorted sequence. At each step, pick the smaller element from the two pointers and advance that pointer. This is the merge step of Merge Sort. Also used when two strings or arrays need to be traversed in sync, comparing or combining elements as you go.

**Problems**

| # | Problem |
|---|---------|
| 1 | MergeSortedArray |
| 2 | BackspaceCompare |
| 3 | FindSmallestCommonElementInAllRows |
| 4 | OneEditDistance |
| 5 | ExpressiveWords |
| 6 | DetermineIfTwoStringsAreClose |
| 7 | ShortestWordDistance |

---

### Pattern 5 — Same Direction (Read / Write)

```
[1, 1, 2, 2, 3, 3]
 w        r
write pointer stays back,
read pointer runs ahead and finds the next valid element
```

Both pointers move in the same direction but at different speeds. The `read` pointer scans the array looking for valid elements. The `write` pointer marks where the next valid element should be placed. When `read` finds something worth keeping, it is written at `write` and `write` advances. Used for all in-place removal and compression problems.

**Problems**

| # | Problem |
|---|---------|
| 1 | RemoveDuplicates |
| 2 | RemoveDuplicatesFromSortedArrayII |
| 3 | KthMissingPositiveNumber |
| 4 | ReverseWordsInAStringII |
| 5 | BuddyStrings |
| 6 | DetectCapital |

---

### Pattern 6 — Sliding Window Variant

```
[2,  3,  1,  2,  4,  3]
 L—————R  →  window expands/shrinks
```

Two pointers define the left and right boundary of a window. The right pointer expands the window to include new elements; the left pointer shrinks it when a condition is violated. This pattern sits at the boundary between two pointers and sliding window — the window size is dynamic and driven by a constraint.

**Problems**

| # | Problem |
|---|---------|
| 1 | SubarrayProductLessThanK |
| 2 | NumberOfSubArraysOfSizeKAndAverageGreaterThanOrEqualToThreshold |
| 3 | SentenceScreenFitting |
| 4 | DegreeOfAnArray |

---

### Miscellaneous

Problems where two pointers play a supporting role but another data structure (hash map, stack) is the primary tool.

| # | Problem |
|---|---------|
| 1 | TwoSumIIIDataStructureDesign |

---

## Complexity Summary

| Pattern | Time | Space |
|---------|------|-------|
| Opposite Ends | O(n) | O(1) |
| Slow and Fast | O(n) | O(1) |
| Partition | O(n) | O(1) |
| Merge Two Sorted | O(n) | O(1) |
| Same Direction | O(n) | O(1) |
| Sliding Window Variant | O(n) | O(1) |

---

> All solutions in this folder use the optimized two pointer approach.  
> Problems sourced from a Meta engineer's curated list for MAANG interview preparation.
