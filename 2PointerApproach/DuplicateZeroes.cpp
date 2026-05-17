Duplicate Zeros #1089
Input:  [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]
Constraint — in place, O(1) space
Before coding — what makes this tricky?

////////////////////////////////////////////////////////////
brute force :  if, in-Place is not needed, We can simply solve it by traversing
TC : O(n) and SC : o(n)


void duplicateZeroes(vector<int>&nums){

    int n = nums.size();
    vector<int>ans;
    for(int i=0; i<n; i++){
        ans.push_back(nums[i]);
        if(nums[i] == 0){
            ans.push_back(0);
        }
    }

    for(int i=0; i<n; i++){
        nums[i] = ans[i];
    }
}

////////////////////////////////////////////
Optimized Approach 
TC : O(n) and SC : O(1);

void duplicateZeros(vector<int>& arr) {

        int n = arr.size();

        int zeros = 0;

        // count zeros
        for(int num : arr) {
            if(num == 0)
                zeros++;
        }

        int i = n - 1;
        int j = n + zeros - 1;

        // move backward
        while(i < j) {

            // write if inside bounds
            if(j < n){
                arr[j] = arr[i];
            }

            // duplicate zero
            if(arr[i] == 0) {

                j--;

                if(j < n)
                    arr[j] = 0;
            }

            i--;
            j--;
        }
    }

//NEED TO COME BACK TO THIS QUESTION AS IT IS BIT CONFUSING
