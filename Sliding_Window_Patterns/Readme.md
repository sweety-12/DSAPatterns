# Sliding Window Approach

> **Specially created for freshers and 0–2 years experience.**

The **Sliding Window** technique maintains a contiguous subarray or substring between two pointers — `left` and `right` — and processes it as a single unit (the "window"). Instead of recomputing results from scratch for every possible subarray (O(n²) or O(n³)), the window slides forward and only processes the element entering and the element leaving at each step, giving **O(n) time and O(1) or O(k) space**.

There are two core flavours:
- **Fixed window** — size is always `k`, both pointers move together.
- **Variable window** — right expands freely, left shrinks when a condition is violated. You track either the maximum or minimum valid window length.

---

## Interview Priority

| Priority | Pattern |
|----------|---------|
| 🔴 1st | Longest substring / subarray (variable window) |
| 🔴 2nd | Fixed size window |
| 🟠 3rd | Minimum / smallest window |
| 🟠 4th | Frequency map window |
| 🟡 5th | Flip / replace at most k |
| 🟡 6th | Count of subarrays |
| 🟢 7th | Deque based max / min |
| 🟢 8th | Max − min ≤ k window |

> Master Tier 1 & 2 patterns first — they cover ~80% of entry level sliding window interviews.

---

## Patterns

### 🔴 Tier 1 — Most Asked Patterns

---

### Pattern 1 — Longest Substring / Subarray (Variable Window)

```
expand right ——>
[a, b, c, a, b, c, b, b]
 L              R
     shrink left when condition breaks, track max length
```

The single most asked pattern at entry level. Almost guaranteed in interviews. Expand the right pointer freely to include new elements. When the window violates the condition (e.g. a duplicate appears, distinct count exceeds k), shrink from the left until the window is valid again. At every step, update the maximum window length seen so far.

**Core idea:** Expand right, shrink left when condition breaks, track max length.

**Problems**

| # | Problem |
|---|---------|
| 1 | Longest substring without repeating characters |
| 2 | Longest substring with at most k distinct characters |
| 3 | Fruits into baskets |
| 4 | Longest subarray with sum = k |

---

### Pattern 2 — Fixed Size Window (Sum / Average)

```
[2,  1,  5,  1,  3,  2]   k = 3
 L———————R
    →  L———————R
           →  L———————R
window size stays fixed at k, slides one step at a time
```

The easiest pattern — usually asked as a warmup or screening question. The window size is always exactly `k`. Add the new element entering from the right, subtract the element leaving from the left, and update your result. No shrinking logic needed.

**Core idea:** Window size is fixed at k, slide one step at a time.

**Problems**

| # | Problem |
|---|---------|
| 1 | Max sum subarray of size k |
| 2 | Average of subarrays of size k |
| 3 | First negative in every window of size k |

---

### 🟠 Tier 2 — Regularly Asked Patterns

---

### Pattern 3 — Minimum Window / Smallest Subarray (Variable Window)

```
expand right until condition met
[a, b, c, a, d, e, b]   target: "abc"
 L——————————R
    L————————R   ← shrink left as much as possible
track min length
```

The opposite of Pattern 1 — instead of finding the longest valid window, you find the smallest. Expand right until the condition is satisfied (e.g. all required characters are present), then shrink left as far as possible while the condition still holds. Record the minimum window size at each valid state.

**Core idea:** Expand right until condition met, then shrink left as much as possible, track min length.

**Problems**

| # | Problem |
|---|---------|
| 1 | Minimum size subarray with sum ≥ k |
| 2 | Minimum window substring |

---

### Pattern 4 — Frequency Map / Character Count Window

```
window: [a, b, c, b, a]
freq map: { a:2, b:2, c:1 }
compare window freq map against target freq map
```

Very common at companies like Amazon and Microsoft for entry level. Maintain a hash map of character (or element) frequencies inside the current window. At each step, update the map as the window slides. Compare the window's frequency map against a target map to check validity — a match means the window is an anagram or permutation of the target.

**Core idea:** Use a hashmap to track character frequencies inside the window.

**Problems**

| # | Problem |
|---|---------|
| 1 | Permutation in string |
| 2 | Find all anagrams in a string |
| 3 | Longest repeating character replacement |

---

### 🟡 Tier 3 — Occasionally Asked Patterns

---

### Pattern 5 — Flip / Replace at Most K Elements (Binary Condition Window)

```
[1, 1, 0, 0, 1, 1, 1, 0, 1]   k = 2 (flip at most 2 zeros)
 L——————————————R   zeros flipped: 2 ✓
     L——————————————R   zeros flipped: 3 ✗ → shrink left
```

Appears in online assessments and product-based company rounds. Track the count of "bad" elements (zeros, non-matching chars) inside the window. As long as the bad count is ≤ k, the window is valid — keep expanding. Once bad count exceeds k, shrink from the left until it is valid again.

**Core idea:** Track count of bad elements, shrink window when bad count exceeds k.

**Problems**

| # | Problem |
|---|---------|
| 1 | Max consecutive ones III (flip at most k zeros) |
| 2 | Longest subarray with at most k replacements |

---

### Pattern 6 — Count of Subarrays (With a Condition)

```
for each valid right pointer:
all windows [left..right], [left+1..right], ..., [right..right]
are valid → add (right - left + 1) to count
```

Asked less frequently but tricky when it appears. Instead of tracking a single window, you count how many valid subarrays exist. The key insight: for a fixed right pointer, every window ending at `right` with a left boundary between `left` and `right` is valid. So the number of new valid subarrays added when right moves forward is `right − left + 1`.

**Core idea:** For each valid right pointer, add `(right − left + 1)` to the total count.

**Problems**

| # | Problem |
|---|---------|
| 1 | Count subarrays with product < k |
| 2 | Count subarrays with exactly k odd numbers |

---

### 🟢 Tier 4 — Rarely Asked at Entry Level

---

### Pattern 7 — Sliding Window Maximum / Minimum (Deque Based)

```
window:  [1, 3, -1, -3, 5, 3, 6, 7]   k = 3
deque tracks indices of potential maximums in decreasing order
→ max of each window: [3, 3, 5, 5, 6, 7]
```

Slightly advanced — more common at 2+ years experience. A brute force max/min scan per window is O(nk). A monotonic deque brings it down to O(n). The deque stores indices of elements in decreasing (for max) or increasing (for min) order. Elements that are out of the window or can never be the answer are evicted from the deque.

**Core idea:** Use a monotonic deque to track max / min without recalculating every window.

**Problems**

| # | Problem |
|---|---------|
| 1 | Sliding window maximum |
| 2 | Sliding window minimum |

---

### Pattern 8 — Max − Min ≤ k Window

```
window: [4, 2, 2, 2, 4, 4, 2, 2]   k = 0
maintain maxDeque and minDeque simultaneously
shrink left when max(window) - min(window) > k
```

Rarely asked at entry level, occasionally seen at FAANG screenings. Combines two monotonic deques running in parallel — one tracking the current window maximum, one tracking the current window minimum. When their difference exceeds k, shrink the window from the left and update both deques accordingly.

**Core idea:** Maintain two deques (one for max, one for min) simultaneously.

**Problems**

| # | Problem |
|---|---------|
| 1 | Longest subarray where max − min ≤ k |

---

## Complexity Summary

| Pattern | Time | Space |
|---------|------|-------|
| Longest substring / subarray | O(n) | O(k) |
| Fixed size window | O(n) | O(1) |
| Minimum window | O(n) | O(k) |
| Frequency map window | O(n) | O(k) |
| Flip / replace at most k | O(n) | O(1) |
| Count of subarrays | O(n) | O(1) |
| Deque based max / min | O(n) | O(k) |
| Max − min ≤ k | O(n) | O(k) |

---

## Learning Order

```
Pattern 1 (Longest Variable Window)
    ↓
Pattern 2 (Fixed Window)
    ↓
Pattern 3 (Minimum Window)
    ↓
Pattern 4 (Frequency Map)
    ↓
Pattern 5 (Flip / Replace k)
    ↓
Pattern 6 (Count Subarrays)
    ↓
Pattern 7 (Deque Max/Min)
    ↓
Pattern 8 (Max − Min ≤ k)
```

> Patterns 1–4 cover ~80% of entry level sliding window questions.  
> All solutions in this folder use the optimized sliding window approach.  
> Problems ranked by interview frequency — sourced and curated for MAANG preparation.
