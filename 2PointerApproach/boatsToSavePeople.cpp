Problem 3 of 4 — Boats to Save People
Difficulty: Medium-Hard

You are given an array people where people[i] is the weight of the i-th person, and an infinite number of boats where each boat can carry at most 2 people at the same time, provided the sum of their weights is at most limit.
Return the minimum number of boats to carry every person.
Input:  people = [1,2], limit = 3
Output: 1
Explanation: 1 boat carries both (1+2=3)

Input:  people = [2,2,2,2], limit = 4
Output: 2
Explanation: Each boat carries 2 people

Input:  people = [3,2,2,1], limit = 3
Output: 3
Explanation: [3],[2],[2,1]
Constraints:

1 <= people.length <= 5 * 10⁴
1 <= people[i] <= limit <= 3 * 10⁴
Each boat carries at most 2 people


BRUTE FORCE :
TC : O(n^2) and SC : O(1)

int no_of_boats(vector<int>& people, int limit) {
    int n = people.size();
    int count = 0;
    vector<bool> taken(n, false);

    sort(people.begin(), people.end());

    // for each heaviest person (right to left)
    for(int i = n-1; i >= 0; i--) {
        if(taken[i]) continue;  // already assigned a boat

        taken[i] = true;
        count++;

        // scan for lightest available person to pair with
        for(int j = 0; j < i; j++) {
            if(!taken[j] && people[i] + people[j] <= limit) {
                taken[j] = true;  // paired!
                break;
            }
        }
    }
    return count;
}


OPTIMIZED APPROACH 
TC : O(nlong) and SC : O(1)

int no_of_boats(vector<int>&people, int limit){

    int count = 0;
    int n = people.size();

    sort(people.begin(), people.end());

    int i=0;
    int j = n-1;

    while(i<=j){

        int pair = people[i] + people[j];

        if(pair <= limit ){
            
           i++
        }
        j--;
        count++;

    }
    return count;
}
