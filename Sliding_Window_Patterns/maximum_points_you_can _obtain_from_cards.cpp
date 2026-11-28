1423. Maximum Points You Can Obtain from Cards

There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

 

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
Example 2:

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.

APPROACH: SLIDING WINDOW
TC: O(n) and SC: O(n)

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        
        vector<int>vec;


        //edge case
        if(n == k){
            //return sum of all
            int sum =0;
            for(int i=0; i<n; i++){
                sum += cardPoints[i];
            }

            return sum;
        }
        
        int windowSum =0;
        //first window
        for(int i=0; i<k ; i++){
            windowSum += cardPoints[i];  //first window
        }

        int maxSum = windowSum;
        int i=k-1;
        int j = n-1;

        while(i >= 0 && j >= n-k){

            windowSum += cardPoints[j] - cardPoints[i];
            
            maxSum = max(windowSum, maxSum);
            i--;
            j--;
        }

        return maxSum;
    }
};
