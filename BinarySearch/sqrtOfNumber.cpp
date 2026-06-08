PATTERN 2 : BINARY SEARCH ON ANSWERS
Finding Sqrt of a number using Binary Search

Problem Statement: You are given a positive integer n. Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor value of sqrt(n).

The idea is that the square root of a number n will always lie between 1 and n. So, we can linearly search in this range to find the largest integer x such that square of x is less than or equal to number n.
Start by creating a variable called ans to hold the result and run a loop from 1 up to n.
While the square of the current number is less than or equal to n, keep updating ans with that number.
As soon as the square of the number becomes greater than n, stop the loop because no bigger number can be the answer.
At the end, the value stored in ans will be the integer square root of n.

BRUTE FORCE :
TC : O(n) and O(1)

int floorSqrt(int n) {
        // Variable to store answer
        int ans = 0;

        // Run loop from 1 to n
        for (int i = 1; i <= n; i++) {
            // Check if i*i <= n
            if ((long long)i * i <= n) {
                // Update answer
                ans = i;
            } else {
                // Break when i*i > n
                break;
            }
        }
        // Return final answer
        return ans;
    }

OPTIMIZED APPROACH :
TC : O(log n) and SC : O(1)

The naive method tries every number, which is slow when n is large. But our possible answer space (from 1 to n) is sorted, meaning if a certain number squared is less than or equal to n, then all smaller numbers will also work. This allows us to apply Binary Search on the answer space to efficiently find the largest number whose square is less than or equal to n.
First, note that the answer lies between 1 and the given number n.
Set the search range with the smallest value as 1 and the largest value as n.
Use binary search within this range to test possible numbers.
At each step, take the middle number and check if its square is less than or equal to n.
If it is, record this number as a candidate and move right to check for a larger number.
If the square is greater than n, move left to check smaller numbers.
Continue this process until the range closes, and the largest recorded number will be the square root.

   int mySqrt(int x) {
        // Handle small numbers directly
        if (x < 2) return x;

        // Initialize binary search range
        int left = 1, right = x / 2, ans = 0;

        // Perform binary search
        while (left <= right) {
            // Find middle point
            long long mid = left + (right - left) / 2;

            // Check if mid*mid is less than or equal to x
            if (mid * mid <= x) {
                // Store mid as potential answer
                ans = mid;
                // Move to right half
                left = mid + 1;
            } else {
                // Move to left half
                right = mid - 1;
            }
        }

        // Return final answer
        return ans;
    }
