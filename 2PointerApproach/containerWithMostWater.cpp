Problem 1 of 4 — Container With Most Water
Difficulty: Medium (but greedy insight is the trap)

Given n vertical lines drawn such that the two endpoints of the i-th line are at (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container that holds the most water.
Return the maximum amount of water a container can store.
Input:  height = [1,8,6,2,5,4,8,3,7]
Output: 49

Input:  height = [1,1]
Output: 1
Constraints:

n == height.length
2 <= n <= 10⁵
0 <= height[i] <= 10⁴

brute force :
TC : O(n^2) and SC : O(1)

int mostWater(vector<int>&height){
    int ans = INT_MIN;
    int n = height.size();
     
    for(int i=0; i<n-1 ; i++){
        for(int j = i+1; j<n; j++){

            int water = min(height[i], height[j]) * (j-i);

            ans = max(ans, water);
        }
    }

    return ans;
}


OPTIMIZED APPROACH :

int mostWater(vector<int>&height){
    int ans = INT_MIN;
    int n = height.size();
    int left =0;
    int right = n-1;

    while(left < right){

        int water = min(height[left], height[right]) * (right - left);

        ans = max(ans, water);

        if(height[left] <= height[right]){
            left++;
        }

        else{
            right--;
        }
    }

    return ans;

}

TC : O(n) and SC : O(1)


A interviewer may ask this as a follow up:

"Why does moving the shorter pointer always work? How do you know you're not missing the optimal pair?"

Answer to internalize:
If height[left] < height[right]:
  - Current water is limited by height[left]
  - Moving right-- will only SHRINK width
  - AND water is still capped by height[left] (or less)
  - So no point moving right → move left++ instead
Moving the taller side can never help. Only the shorter side has a chance of improvement.
