Find Nth root of a number
Given two numbers N and M, find the Nth root of M. The Nth root of a number M is defined as a number X such that when X is raised to the power of N, it equals M. If the Nth root is not an integer, return -1.
Example 1
Input: N = 3, M = 27
Output: 3
Explanation: The cube root of 27 is equal to 3.
Example 2
Input: N = 4, M = 69
Output:-1
Explanation: The 4th root of 69 does not exist. So, the answer is -1.

Constraints :
1 <= N <= 30
1 <= M <= 109

First Approach : Using Pow function(THIS WILL PASS MOST OF THE TESTCASES BUT CAN THROW OVERFLOW CONDTION AT LARGER NUMBER)
(MY APPROACH)

int NthRoot(int N, int M) {
       
       int low = 1;
       int high = M;
      

       while(low <= high){

        int  mid = (low + high) / 2;

        long long power = pow(mid, N);

        if(M == power)  return mid;

        else if (M < power){
            high = mid -1;
        }

        else{
            low = mid + 1;
        }
       }

       return -1;
    }

Here’s a simple interview-friendly explanation:

### Why avoid pow()?

The function pow(a, b) returns a double (floating-point number), not an integer.
Floating-point values can lose precision
For large powers, the result may be slightly off due to rounding.

Example
The true value is 50031545098999707, but the computed double may be stored as something like 50031545098999704 or 50031545098999712.

Then a comparison like:
may fail even though mathematically it should be true.

Overflow issues
For very large values, pow(mid, N) can exceed the range of long long. 
Converting that huge floating-point value back to an integer is unreliable and can even lead to undefined behavior.

### What should we do instead?
Use integer multiplication with early stopping:

This approach:

1. Uses only integer arithmetic.
2. Avoids floating-point precision errors.
3. Lets you stop early when the value exceeds M.

### One-line interview answer
I avoid using pow() in binary-search root problems because it returns a floating-point value,
which can introduce precision and overflow issues for large powers. Using integer multiplication 
is safer and guarantees exact comparisons.

Failing Example:
N = 35, M = 50031545098999707 (find 35th root of M)

STRIVER'S APPROACH (ITERATIVE ONE)

int check(int mid, int N, int M) {
    long long ans = 1;

    for(int i = 0; i < N; i++) {
        ans *= mid;

        if(ans > M)
            return 2;   // greater than M
    }

    if(ans == M) return 1;
    return 0;           // less than M
   }

    int nthRoot(int N, int M) {
        // Code here
        
    if(M == 0)  return 0;
    
    int low = 1;
    int high = M;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        int val = check(mid, N, M);

        if(val == 1)
            return mid;
        else if(val == 2)
            high = mid - 1;
        else
            low = mid + 1;
    }

  return -1;
}



  
