# Sliding Window --- Master Interview Preparation Sheet

> Consolidated from my original Sliding Window notes and the LeetCode
> pattern list. Target: fresher to 0--2 years experience, with selected
> advanced problems for stronger interview preparation.

## Problem count

-   **62 problem entries** across the patterns and additional DSA
    section.
-   **49 distinct problems** after accounting for problems repeated
    under multiple patterns or listed under equivalent names.
-   Repeated entries are intentional where a problem teaches more than
    one technique.

## Pattern 1 --- Fixed-Size Sliding Window

**Priority: 1 --- Must Do**

**Core idea:** Maintain a window of exactly size `k`. Add the incoming
element and remove the outgoing element.

  -----------------------------------------------------------------------
  \#                      Problem                 Source
  ----------------------- ----------------------- -----------------------
  1                       Maximum Sum Subarray of Original notes
                          Size K                  

  2                       Average of Subarrays of Original notes
                          Size K                  

  3                       First Negative Number   Original notes
                          in Every Window of Size 
                          K                       

  4                       Maximum Average         LeetCode addition
                          Subarray I              

  5                       Maximum Sum of Distinct LeetCode addition
                          Subarrays With Length K 

  6                       Contains Duplicate II   LeetCode addition

  7                       K Radius Subarray       LeetCode addition
                          Averages                

  8                       Maximum Points You Can  LeetCode addition
                          Obtain from Cards       

  9                       Maximum Vowels in a     LeetCode addition
                          Substring of Given      
                          Length                  
  -----------------------------------------------------------------------

## Pattern 2 --- Variable-Size Window: Longest Valid Window

**Priority: 1 --- Must Do**

**Core idea:** Expand `right`, shrink `left` when the condition breaks,
and track the maximum length.

  -----------------------------------------------------------------------
  \#                      Problem                 Source
  ----------------------- ----------------------- -----------------------
  1                       Longest Substring       Original notes
                          Without Repeating       
                          Characters              

  2                       Longest Subarray With   Original notes
                          Sum = K                 

  3                       Longest Subarray of 1s  LeetCode addition
                          After Deleting One      
                          Element                 

  4                       Maximum Erasure Value   LeetCode addition

  5                       Longest Semi-Repetitive LeetCode addition
                          Substring               
  -----------------------------------------------------------------------

**Important:** The standard sum-based sliding window for
`Longest Subarray With Sum = K` requires non-negative elements. For
arbitrary integers, use Prefix Sum + HashMap.

## Pattern 3 --- Variable-Size Window: Minimum Valid Window

**Priority: 1 --- Must Do**

**Core idea:** Expand until the condition is satisfied, then shrink as
much as possible while maintaining validity.

  -----------------------------------------------------------------------
  \#                      Problem                 Source
  ----------------------- ----------------------- -----------------------
  1                       Minimum Size Subarray   Original notes
                          Sum                     

  2                       Minimum Window          Original notes
                          Substring               

  3                       Shortest Subarray to Be LeetCode addition
                          Removed to Make Array   
                          Sorted                  
  -----------------------------------------------------------------------

### Advanced extension

  -----------------------------------------------------------------------
  \#                      Problem                 Technique
  ----------------------- ----------------------- -----------------------
  4                       Shortest Subarray With  Prefix Sum + Monotonic
                          Sum at Least K          Deque

  -----------------------------------------------------------------------

**Important:** `Shortest Subarray With Sum at Least K` is not a normal
variable-size sliding-window problem when negative numbers are allowed.

## Pattern 4 --- Frequency Map / Character Count Window

**Priority: 1 --- Must Do**

**Core idea:** Maintain character or element frequencies using a HashMap
or frequency array.

  -----------------------------------------------------------------------
  \#                      Problem                 Source
  ----------------------- ----------------------- -----------------------
  1                       Longest Substring With  Original notes
                          At Most K Distinct      
                          Characters              

  2                       Fruits Into Baskets     Original notes

  3                       Permutation in String   Original notes

  4                       Find All Anagrams in a  Original notes
                          String                  

  5                       Longest Repeating       Original notes
                          Character Replacement   

  6                       Longest Substring With  LeetCode addition
                          At Most Two Distinct    
                          Characters              

  7                       Substring With          LeetCode addition
                          Concatenation of All    
                          Words                   

  8                       Count Complete          LeetCode addition
                          Substrings              

  9                       Longest Substring With  LeetCode addition
                          Equal Character         
                          Frequency               
  -----------------------------------------------------------------------

**Note:** The last two require specialized frequency constraints; they
are not just applications of the simplest frequency-map template.

## Pattern 5 --- At Most K / Exactly K Subarrays

**Priority: 2 --- Must Do**

**Core idea:**

``` text
Exactly(K) = AtMost(K) - AtMost(K - 1)
```

  -----------------------------------------------------------------------
  \#                      Problem                 Source
  ----------------------- ----------------------- -----------------------
  1                       Count Subarrays With    Original notes
                          Exactly K Odd Numbers   

  2                       Subarrays With K        LeetCode addition
                          Different Integers      

  3                       Binary Subarrays With   LeetCode addition
                          Sum                     

  4                       Number of Substrings    LeetCode addition
                          Containing All Three    
                          Characters              

  5                       Subarray Product Less   Original notes /
                          Than K                  LeetCode
  -----------------------------------------------------------------------

**Important:** `Subarray Product Less Than K` uses an at-most-style
counting window, but not the Exactly K subtraction formula.

## Pattern 6 --- Flip / Replace at Most K Elements

**Priority: 2 --- Important**

**Core idea:** Track the number of invalid elements and keep their count
at most `k`.

  \#   Problem                                        Source
  ---- ---------------------------------------------- ----------------
  1    Max Consecutive Ones III                       Original notes
  2    Longest Subarray With At Most K Replacements   Original notes

**Related problem:** `Longest Repeating Character Replacement` is listed
under Pattern 4 because it combines a frequency map with a replacement
constraint.

## Pattern 7 --- Sum / Product Constraint Windows

**Priority: 2 --- Important**

**Core idea:** Maintain a running sum or product and shrink the window
when the constraint is violated.

  -----------------------------------------------------------------------
  \#                      Problem                 Source
  ----------------------- ----------------------- -----------------------
  1                       Longest Subarray With   Original notes
                          Sum = K                 

  2                       Minimum Size Subarray   Original notes
                          Sum                     

  3                       Subarray Product Less   Original notes
                          Than K                  

  4                       Maximum Sum of Distinct LeetCode addition
                          Subarrays With Length K 

  5                       Maximum Points You Can  LeetCode addition
                          Obtain from Cards       
  -----------------------------------------------------------------------

**Note:** Some problems also appear in other patterns. These repeated
entries are cross-references, not additional unique questions.

## Pattern 8 --- Prefix Sum + HashMap / Sliding Window

**Priority: 2 --- Important**

**Core idea:** Use prefix sums to handle subarray-sum conditions where
ordinary window shrinking is not reliable.

  -----------------------------------------------------------------------
  \#                      Problem                 Source
  ----------------------- ----------------------- -----------------------
  1                       Longest Subarray With   Original notes
                          Sum = K (general        
                          integers)               

  2                       Subarray Sum Equals K   LeetCode addition

  3                       Continuous Subarray Sum LeetCode addition

  4                       Minimum Operations to   LeetCode addition
                          Reduce X to Zero        

  5                       Find Pivot Index        LeetCode addition
  -----------------------------------------------------------------------

**Technique notes:** - `Subarray Sum Equals K` → Prefix Sum + HashMap. -
`Continuous Subarray Sum` → Prefix Sum + Remainder HashMap. -
`Minimum Operations to Reduce X to Zero` → Transform into a
longest-subarray-sum problem. - `Find Pivot Index` → Prefix Sum; it is
not really a sliding-window problem.

## Pattern 9 --- Monotonic Deque: Sliding Window Maximum / Minimum

**Priority: 3 --- Important**

**Core idea:** Maintain a monotonic deque to efficiently track maximum
and minimum values.

  -----------------------------------------------------------------------
  \#                      Problem                 Source
  ----------------------- ----------------------- -----------------------
  1                       Sliding Window Maximum  Original notes

  2                       Sliding Window Minimum  Original notes

  3                       Longest Subarray Where  Original notes
                          Max − Min ≤ K           

  4                       Longest Continuous      LeetCode addition
                          Subarray With Absolute  
                          Diff Less Than or Equal 
                          to Limit                

  5                       Shortest Subarray With  LeetCode addition
                          Sum at Least K          

  6                       Sliding Window Median   LeetCode addition

  7                       Constrained Subsequence LeetCode addition
                          Sum                     

  8                       Sum of Subarray         LeetCode addition
                          Minimums                
  -----------------------------------------------------------------------

**Important distinctions:** - `Longest Subarray Where Max − Min ≤ K` and
`Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit`
refer to the same underlying LeetCode problem. -
`Shortest Subarray With Sum at Least K` uses Prefix Sum + Monotonic
Deque. - `Sliding Window Median` uses two heaps or an ordered data
structure. - `Constrained Subsequence Sum` combines a monotonic deque
with Dynamic Programming. - `Sum of Subarray Minimums` is primarily a
Monotonic Stack problem.

## Pattern 10 --- Dual Windows / Advanced Two Pointers

**Priority: 3 --- Advanced**

**Core idea:** Maintain two related windows or combine sliding window
with specialized state tracking.

  -----------------------------------------------------------------------
  \#                      Problem                 Source
  ----------------------- ----------------------- -----------------------
  1                       Longest Nice Subarray   LeetCode addition

  2                       Substring With          LeetCode addition
                          Concatenation of All    
                          Words                   

  3                       Number of Substrings    LeetCode addition
                          Containing All Three    
                          Characters              

  4                       Subarrays With K        LeetCode addition
                          Different Integers      

  5                       Count Complete          LeetCode addition
                          Substrings              
  -----------------------------------------------------------------------

**Note:** Some problems are cross-listed because they combine frequency
maps, multiple windows, or two pointers. `Longest Nice Subarray` is
particularly useful for learning bitmask-based window state.

## Additional DSA Problems Worth Knowing

These appeared in the LeetCode list but do not fit cleanly into the 10
core patterns.

  \#   Problem                                  Primary DSA topic
  ---- ---------------------------------------- --------------------------
  1    K Divisible Elements Subarrays           Hashing + Enumeration
  2    Maximum Subarray Sum With One Deletion   Dynamic Programming
  3    Prefix and Suffix Search                 Trie + String Processing
  4    Daily Temperatures                       Monotonic Stack
  5    Sum of Subarray Minimums                 Monotonic Stack

## Recommended Learning Order

1.  Patterns 1--4: Fixed window, longest window, minimum window,
    frequency map.
2.  Patterns 5--8: Exactly K, replacements, sum/product constraints,
    prefix sums.
3.  Patterns 9--10: Monotonic deque, dual windows, advanced two
    pointers.
4.  Finish with the additional DSA problems where relevant.

## Interview Reminders

-   Sliding Window is not suitable for every subarray problem.
-   Standard sum-based expand/shrink windows generally rely on
    non-negative (or positive, depending on the problem) array elements.
-   For arbitrary integers, consider Prefix Sum + HashMap or Prefix
    Sum + Monotonic Deque.
-   Learn why a window is valid and when it becomes invalid; do not just
    memorize templates.
-   A problem may belong to more than one pattern. Count it once when
    tracking unique problems.
